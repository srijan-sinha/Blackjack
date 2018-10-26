IDIR = ./include
CC = g++
CFLAGS = -I$(IDIR) -std=c++11

ODIR = ./build
SDIR = ./src
EDIR = ./bin

_DEPS = Game.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Game.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o : $(SDIR)/%.cpp $(DEPS)
	$(CC) -O3 -c -o $@ $< $(CFLAGS)

$(EDIR)/main : $(OBJ)
	$(CC) -O3 -o $@ $^ $(CFLAGS) -g

.PHONY: clean

clean:
	rm -rf ./bin/* ./build/*.o