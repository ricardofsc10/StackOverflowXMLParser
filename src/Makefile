IDIR=../include
ODIR=obj
LDIR=../lib
OLDIR=$(LDIR)/obj

CC=gcc
CFLAGS = -Wall -std=c11 -g `pkg-config --cflags libxml-2.0` `pkg-config --cflags glib-2.0` -I$(IDIR)

DEPS=$(IDIR)/$(wildcard *.h)
SOURCES=$(wildcard *.c)
MY_LIBS=$(wildcard $(LDIR)/*.c)
SOURCES_OBJ=$(patsubst %.c,%.o,$(SOURCES))
MY_LIBS_OBJ=$(patsubst %.c,%.o,$(MY_LIBS))
LIBS = `pkg-config --libs libxml-2.0` `pkg-config --libs glib-2.0`

print-% : ; @echo $* = $($*)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $(ODIR)/$(notdir $@) $<

objects: $(SOURCES_OBJ) $(MY_LIBS_OBJ)

SOURCES_OBJ2=$(ODIR)/$(patsubst %.c,%.o,$(SOURCES))
MY_LIBS_OBJ2=$(foreach o, $(notdir $(patsubst %.c,%.o,$(MY_LIBS))), $(ODIR)/$o)

program: $(SOURCES_OBJ2) $(MY_LIBS_OBJ2)
	$(CC) $(CFLAGS) $(wildcard obj/*.o) -o program $(LIBS)

clean:
	rm obj/*
	rm program
