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
    std::cin >> RelativePath;

    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(RelativePath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG){ 
                std::string fPath = RelativePath + "/" + ent->d_name;

                if (strEndsWith(fPath, ".crypt-validation.txt")) { continue; }

                // Create stream
                std::ofstream wfstream(fPath);
                wfstream << "Greetings from Main.cpp!";
                wfstream.close();
            }
        }

        closedir(dir);
    } else {
        std::cout << "Couldn't open dir :/\n";
        return 1;
    }

    return 0;
}   