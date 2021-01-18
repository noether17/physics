SYSTEM_TYPE := $(shell uname)

ifeq ($(PHYSICS_ROOT),)
PHYSICS_ROOT = ./
endif

include $(PHYSICS_ROOT)/Make.flags.$(SYSTEM_TYPE)
CC = gcc
CPP = g++
CFLAGS = -Wall -O3 -lm

#all: bld ray
all: source

source:
	cd common; \
		$(MAKE)
	cd nbody_simulator; \
		$(MAKE)
	cd ray_optics; \
		$(MAKE)

clean:
	cd general; \
		$(MAKE) clean
	cd nbody_simulator; \
		$(MAKE) clean
	cd ray_optics; \
		$(MAKE) clean

#bld:
#	mkdir -p bld
#
#ray:
#	$(CPP) src/ray_optics/ray_optics_test.cpp -o bld/ray_optics_test
#
#clean:
#	rm bld/*
