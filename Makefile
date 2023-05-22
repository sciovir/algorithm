CC = gcc
CFLAGS = -Wall -Wextra -pedantic
STD = -std=c17
OUTDIR = binf

all: fibonacci

fibonacci: mathematics/fibonacci.c
	$(CC) $(STD) $(CFLAGS) -o $(OUTDIR)/fibonacci mathematics/fibonacci.c

clean:
	rm -f $(OUTDIR)/*