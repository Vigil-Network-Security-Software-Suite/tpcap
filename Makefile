all: main clean

CC=g++
CFLAGS=-Wall



main.o:
	$(CC) $(CFLAGS) -c main.cpp
globals.o:
	$(CC) $(CFLAGS) -c src/globals.cpp
decode.o:
	$(CC) $(CFLAGS) -c src/decode/decode.cpp
eth.o:
	$(CC) $(CFLAGS) -c src/decode/eth.cpp
utils.o:
	$(CC) $(CFLAGS) -c src/utils.cpp
main: main.o globals.o decode.o eth.o utils.o
	$(CC) $(CFLAGS) -o tpcap.exe $^

clean:
	rm *.o