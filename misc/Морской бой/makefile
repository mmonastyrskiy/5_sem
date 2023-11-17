OBJS	= Board.o Game.o  main.o
SOURCE	= Board.cpp Game.cpp main.cpp
HEADER	= Board.hpp Game.hpp 
OUT	= morscoyboy.exe
CC	 = g++
CC2  = x86_64-w64-mingw32-gcc 
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp 

Game.o: Game.cpp
	$(CC) $(FLAGS) Game.cpp 

Ship.o: Ship.cpp
	$(CC) $(FLAGS) Ship.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)
all-windows: $(OBJS)
	$(CC2) -o $(OUT) $(OBJS)

