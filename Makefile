CC=clang++
CFLAGS=-Wall -O3
LDLAGS=
DEBUGFLAGS=-g
OUTPUT=random-sort

all: main

main:
	$(CC) $(CFLAGS) $(LDFLAGS) *.cpp -o $(OUTPUT)

.PHONY: clean
clean:
	rm $(OUTPUT)

debug: CFLAGS += $(DEBUGFLAGS)
debug: all