#include <stdio.h>
#include <errno.h> 
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>


#define DEBUG 1
#define INT_LIMIT 101
#define CHILD_AMMOUNT_PRESET 100
#define SIZE_MULT pow(10,0)

typedef int** Matrix;

Matrix allocate_matrix(size_t N) {
int i;
 Matrix array = (int**)malloc(N * sizeof(int*));
    for (i = 0; i < N; i++) {
        array[i] = (int*)malloc(N * sizeof(int));
    }
	return array;
}

int* get_col_by_idx(Matrix m,int index, size_t size){
	int i;
	int* result = malloc(sizeof(int)* size);
	if (index > size * SIZE_MULT){
		return NULL;
	}
	for(i=0;i<size*SIZE_MULT;i++){
		result[i] = m[i][index];
	}
	return result;

}

int mult_rnc(int row[], int col[], size_t size){
	int i;
	int r;
	r = 0;
	for(i=0;i<size;i++){
		r += row[i]*col[i];
	}
	return r;
}

void mult(Matrix m1, Matrix m2,Matrix res,size_t size){
	pid_t ppid;
	int ready;
	pid_t pids[CHILD_AMMOUNT_PRESET];
	int pipefd[CHILD_AMMOUNT_PRESET][2];
	int nfds, num_open_fds;
    struct pollfd *pfds;
    int i,row_index,j;
	int* col;
	int semi_res[size];
    Matrix result;
	result = res;

	ppid = getpid();

    num_open_fds = nfds = size;
    pfds = calloc(nfds, sizeof(struct pollfd)*CHILD_AMMOUNT_PRESET);
	if (pfds == NULL){
		perror("Error on calloc pollfd");
		exit(3);
	}
	for(i=0;i<CHILD_AMMOUNT_PRESET;i++){
		if(pipe(pipefd[i])==-1){
            printf("pipe");
            exit(2);
        }
		pfds[i].fd = pipefd[i][0];
        pfds[i].events = POLLIN;

	}
	for(i=0;i < CHILD_AMMOUNT_PRESET; i++){
		if(getpid()== ppid){
			row_index =i;
			pids[i] = fork();
			#if DEBUG
			dprintf(STDOUT_FILENO, "Process %d is created\n", i);
			#endif
			

		}
		else{
		if (getpid() == 0){
		for(j=0;j<size;j++){
			col = get_col_by_idx(m2,j,size);
			semi_res[j]=mult_rnc(m1[row_index],col,size);
			dprintf(STDOUT_FILENO, "Data transmitted");
			write(pipefd[row_index][1],semi_res,sizeof(int)*size);
			close(pipefd[row_index][0]);
			close(pipefd[row_index][1]);
			exit(0);

			}
		
	}
	    while(num_open_fds > 0){
        for (i = 0; i < size; i++) pfds[i].revents=0;
         if ((ready = poll(pfds, nfds, -1)) == -1) {
            printf("poll error");
            exit(10);
         }
	for(j=0;j<size;j++){
		if(pfds[j].revents & POLLIN){
		read(pipefd[j][0],result[j],sizeof(int)*size);
		#if DEBUG
		dprintf(STDOUT_FILENO,"Thread %d Transmitted data\n",j);
		#endif

	 	if(pfds[i].revents & POLLHUP){
    	dprintf(STDOUT_FILENO,"POLLHUP\n");
      close(pfds[i].fd);
      pfds[i].fd = -1;
      pfds[i].events=0;
      num_open_fds--;
    }
    else if(pfds[i].revents & POLLHUP){
    	dprintf(STDOUT_FILENO,"POLLHUP\n");
      close(pfds[i].fd);
      pfds[i].fd = -1;
      pfds[i].events=0;
      num_open_fds--;
		
	}

			}
	






}
}
}
}
}
void print_matrix(Matrix m, size_t N){
	size_t x;
	size_t y;
	size_t MSIZE;
	MSIZE = N*SIZE_MULT;
	printf("\n");
	for (y=0; y< MSIZE;y++){
		for (x=0; x< MSIZE;x++){
			printf("%d[%ld][%ld]|\t", m[y][x],y,x);

}
	printf("\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n");
}
}



void fill_matrix(Matrix m, size_t N) {
  size_t x;
  size_t y;
  size_t MSIZE;
  MSIZE = N * SIZE_MULT;
  for (y = 0; y < MSIZE; y++) {
    for (x = 0; x < MSIZE; x++) {
      m[y][x] = rand() % INT_LIMIT;
      #if DEBUG
      /*printf("Generated int: %d on [%ld][%ld]\n\n", m[y][x], y, x);*/
      #endif
    }
  }
  printf("Matrix filled");
  return;
}


int main(int argc, char const *argv[])
{
	size_t N;
	size_t MSIZE;
	Matrix m1;
	Matrix m2;
	Matrix res;

	srand(time(NULL));
	if (argc < 2){
		perror("Bad usage, the correct one is ./a.out <N>");
		 return 1;
	}
	N = atoi(argv[1]);
	MSIZE = N*( unsigned long int)SIZE_MULT;
	#if DEBUG
	printf(" Entered N = %ld\n",N);
	printf("%f\n",SIZE_MULT);
	printf("%ld",MSIZE);
	#endif
	m1 = allocate_matrix(N);
	m2 = allocate_matrix(N);
	res = allocate_matrix(N);
	
	fill_matrix(m1, N);
	fill_matrix(m2, N);
	
	#if DEBUG
	print_matrix(m1,N);
	print_matrix(m2,N);
	
	#endif
	mult(m1,m2,res,N);
	print_matrix(res,N);

	free(res);
	free(m1);
	free(m2);




	return 0;
}
