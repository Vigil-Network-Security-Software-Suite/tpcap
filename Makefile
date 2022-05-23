all: main clean

CC=g++
CFLAGS=-Wall



main.o:
	$(CC) $(CFLAGS) -c main.cpp
globals.o:
	$(CC) $(CFLAGS) -c src/globals.cpp
decode.o:
	$(CC) $(CFLAGS) -c src/decode/decode.cpp

main: main.o globals.o decode.o
	$(CC) $(CFLAGS) -o tpcap.exe $^

clean:
	rm *.o