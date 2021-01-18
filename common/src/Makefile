SYSTEM_TYPE := $(shell uname)

ifeq ($(PHYSICS_ROOT),)
PHYSICS_ROOT = ../../
endif

include $(PHYSICS_ROOT)/Make.flags.$(SYSTEM_TYPE)

INCDIRS = \
	-I$(PHYSICS_ROOT) \
	-I$(PHYSICS_ROOT)/common/include

SRC = \
	Vector.c

LINKLIBS  = -lm
OUTPUTARC = libCommon.a
#OUTPUTLIB = libCommon.so

OBJ = $(SRC:.c=.o)

all: libarchive

libarchive: common $(OUTPUTARC)

common: $(OBJ)

$(OUTPUTARC):
	-ar -crsv $(OUTPUTARC) $(OBJ)

clean:
	-rm -f *.o
	-rm -f $(OUTPUTARC)

# rules for compilation
.c.a:
	$(CC) $(CFLAGS) $(INCDIRS) -c `pwd`/$<
.c.o:
	$(CC) $(CFLAGS) $(INCDIRS) -c `pwd`/$<