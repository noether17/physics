SYSTEM_TYPE := $(shell uname)

ifeq ($(PHYSICS_ROOT),)
PHYSICS_ROOT = ../
endif

include $(PHYSICS_ROOT)/Make.flags.$(SYSTEM_TYPE)

all: source

source:
	cd src; \
		$(MAKE)

clean:
	cd src; \
		$(MAKE) clean