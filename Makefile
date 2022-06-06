all: main clean

CC=gcc
CFLAGS=-Wall



main.o:
	$(CC) $(CFLAGS) -c main.c
globals.o:
	$(CC) $(CFLAGS) -c src/globals.c
decode.o:
	$(CC) $(CFLAGS) -c src/decode/decode.c
eth.o:
	$(CC) $(CFLAGS) -c src/decode/eth.c
utils.o:
	$(CC) $(CFLAGS) -c src/utils.c
main: main.o globals.o decode.o eth.o utils.o
	$(CC) $(CFLAGS) -o tpcap.exe $^

clean:
	rm *.o