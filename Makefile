CC = gcc
CPP = g++
CFLAGS = -Wall -O3 -lm

all: bld ray

bld:
	mkdir -p bld

ray:
	$(CPP) src/ray_optics/ray_optics_test.cpp -o bld/ray_optics_test

clean:
	rm bld/*
