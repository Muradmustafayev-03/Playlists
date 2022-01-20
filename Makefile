CC=gcc

LDFLAGS= -Wall -pedantic
CFLAGS= -lm

SOURCES=main.c song.c playlist.c statPlot.c pbPlots.c supportLib.c

OBJECTS=main.o song.o playlist.o statPlot.o pbPlots.o supportLib.o

EXECUTABLE=main

all: $(EXECUTABLE) $(SOURCES)


$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(CFLAGS)
	make clean

clean:
	rm -f *.o
