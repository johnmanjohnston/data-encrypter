// // C++, OH MY FREAKIN GOODNESS I SWEAR, YOU MAKE ME WANT TO BANG MY HEAD AGAINST A WALL AND WISH FOR THE SWEET RELEASE OF DEATH

#include <iostream>
#include <dirent.h>
#include <fstream>
#include <string_view>
#include "../headers/Crypt.h"

// Definitions 
std::string RelativePath;
std::string CryptionKey;

inline bool strEndsWith(std::string const &orgStr, std::string const &suffix) {
    // If suffix size > original string, it isn't possible to have the orginal string contain the suffix
    if (suffix.size() > orgStr.size()) { return false; }

    bool ends = std::equal(suffix.rbegin(), suffix.rend(), orgStr.rbegin());
    return ends;
}

int main() {
    std::cout << "Enter the path of the files of the directory you want to crypt: ";
    std::cin >> RelativePath;

    std::cout << "Enter your cryption key: ";
    std::cin >> CryptionKey;

    CryptHandler ch;
    ch.Encrypt(RelativePath, "demo-key");

    return 0;
}   