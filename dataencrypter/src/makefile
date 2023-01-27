CC = g++
CFLAGS = -lstdc++ -std=c++17
TARGET = dataencrypter

main: main.o crypt.o
	$(CC) $(CFLAGS) -o main main.o crypt.o

main.o: Main.cpp 
	$(CC) $(CFLAGS) -c Main.cpp -o main.o

crypt.o: Crypt.cpp 
	$(CC) $(CFLAGS) -c Crypt.cpp -o crypt.o

clean:
	rm main.o crypt.o