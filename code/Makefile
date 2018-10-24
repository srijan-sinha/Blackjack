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
	$(CC) -c -o $@ $< $(CFLAGS)

$(EDIR)/main : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -g

.PHONY: clean

clean:
	rm -rf ./bin/* ./build/*.o