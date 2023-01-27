// C++, OH MY FREAKIN GOODNESS I SWEAR, YOU MAKE ME WANT TO BANG MY HEAD AGAINST A WALL AND WISH FOR THE SWEET RELEASE OF DEATH

// #includes
#include <iostream>
#include <string>
#include <filesystem>
#include <iostream>
#include "../headers/Utils.h"
#include "../headers/Crypt.h"

int main() {
    std::cout << "Main.cpp working";
    std::cin >> TargetCryptionDir;

    for (const auto & entry : std::filesystem::directory_iterator(TargetCryptionDir)) {
        std::cout << entry.path() << std::endl;
    }
    
    return 0;
}