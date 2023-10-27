#include <stdio.h>
#include <errno.h> 
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


#define DEBUG 1
#define INT_LIMIT 101
#define CHILD_AMMOUNT_PRESET 100
#define SIZE_MULT pow(10,3)

typedef int** Matrix;


int mult_rnc(int row[], int col[], size_t size){
	int i;
	int r;
	r = 0;
	for(i=0;i<size;i++){
		r += row[i]*col[i];
	}
	return r;
}

Matrix mult(Matrix m1, Matrix m2,size_t size){
	pid_t pids[CHILD_AMMOUNT_PRESET];
	int pipefd[CHILD_AMMOUNT_PRESET][2];
	int nfds, num_open_fds;
    struct pollfd *pfds;
    int i;
    Matrix result;
/*TODO: дописать логику перемножения */

    num_open_fds = nfds = size;
    pfds = calloc(nfds, sizeof(struct pollfd));
	if (pfds == NULL){
		perror("Error on calloc pollfd");
		exit(3);
	}
	return result;




}

int* get_col_by_idx(Matrix m,size_t index, size_t size){
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

void print_matrix(Matrix m, size_t N){
	size_t x;
	size_t y;
	size_t MSIZE;
	MSIZE = N*SIZE_MULT;
	for (y=0 < MSIZE;y++;){
		for (x=0 < MSIZE;x++;){
			printf("%d\t", m[y][x]);

}
	printf("\n");
}
}

void fill_matrix(Matrix m, size_t N){
	size_t x;
	size_t y;
	size_t MSIZE;
	MSIZE = N*SIZE_MULT;
	srand(time(NULL));
	for (y=0 < MSIZE;y++;){
		for (x=0 < MSIZE;x++;){
			m[y][x]= rand()%INT_LIMIT;
			break;
			#if DEBUG
			printf("Generated int :%d on [%ld][%ld]\n",m[y][x],y,x);
			#endif
		}
	}
}

Matrix* allocate_matrix(size_t N){
	int i;
	size_t MSIZE;
	Matrix* matrix = malloc(sizeof(int*)*N*SIZE_MULT);
	MSIZE = N*SIZE_MULT;

	if(matrix == NULL){
		perror("Error on malloc matrix");
		exit(2);
	}
	for(i=0;i< MSIZE;i++){
		matrix[i] = malloc(sizeof(int) * MSIZE);
	}
	return matrix;
}
int main(int argc, char const *argv[])
{
	size_t N;
	size_t MSIZE;
	Matrix* m1;
	Matrix* m2;


	if (argc < 2){
		perror("Bad usage, the correct one is ./a.out <N>");
		 return 1;
	}
	N = atoi(argv[1]);
	#if DEBUG
	printf(" Entered N = %ld\n",N);
	#endif
	MSIZE = N*SIZE_MULT;
	#if DEBUG
	printf("%ld",MSIZE);
	#endif
	m1 = allocate_matrix(N);
	m2 = allocate_matrix(N);
	fill_matrix(*m1, N);
	fill_matrix(*m2, N);
	#if DEBUG
	print_matrix(*m1,N);
	print_matrix(*m2,N);
	#endif





	return 0;
}