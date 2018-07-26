UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
        CC=g++
    endif
    ifeq ($(UNAME_S),Darwin)
        CC=clang++
    endif
CFLAGS=-lgsl -lgslcblas -std=c++11
DEPS = entropy.h gameOfLife.h gasMixing.h randomv.h lodepng.h system.h
opt:	main.cpp entropy.cpp gameOfLife.cpp gasMixing.cpp randomv.cpp lodepng.cpp system.cpp
		$(CC) -O3 -Wall -o run main.cpp entropy.cpp gameOfLife.cpp gasMixing.cpp randomv.cpp lodepng.cpp system.cpp $(CFLAGS)
run:	main.cpp entropy.cpp gameOfLife.cpp gasMixing.cpp randomv.cpp lodepng.cpp system.cpp
	$(CC) -Wall -o run main.cpp entropy.cpp gameOfLife.cpp gasMixing.cpp randomv.cpp lodepng.cpp system.cpp $(CFLAGS)
