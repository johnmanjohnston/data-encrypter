// // C++, OH MY FREAKIN GOODNESS I SWEAR, YOU MAKE ME WANT TO BANG MY HEAD AGAINST A WALL AND WISH FOR THE SWEET RELEASE OF DEATH

#include <iostream>
#include <dirent.h>
#include <fstream>

// Definitions 
std::string RelativePath;
std::string CryptionKey;

int main() {
    std::cin >> RelativePath;

    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(RelativePath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG){ 
                // Ignore .crypt-validation.txt
                std::cout << ent->d_name << std::endl;

                std::string fPath = RelativePath + "/" + ent->d_name;

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