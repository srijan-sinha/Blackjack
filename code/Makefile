IDIR = ./include
CC = g++
CFLAGS = -I$(IDIR) -std=c++11

ODIR = ./build
SDIR = ./src
EDIR = ./bin

_DEPS = Markov.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Markov.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o : $(SDIR)/%.o $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EDIR)/main : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf ./bin/* ./build/*.o