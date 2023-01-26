#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <stdbool.h>    

bool FileExists (char *filename) {
  struct stat buffer;   
  return (stat(filename, &buffer) == 0);
}

int main() {
    // To fix: main.out created in current dir
    if (FileExists("Main.cpp")) {
        system("g++ -std=c++17 Main.cpp -lstdc++ -o main.out");
        system("./main.out");
    } else {
        system("g++ -std=c++17 src/Main.cpp -lstdc++ -o src/main.out");
        system("./src/main.out");
    }

    return 0;
}