#include "../headers/Crypt.h"
#include <fstream>
#include <dirent.h>
#include <iostream>

// Move this to a seperate file later:
inline bool strEndsWith(std::string const &orgStr, std::string const &suffix) {
    // If suffix size > original string, it isn't possible to have the orginal string contain the suffix
    if (suffix.size() > orgStr.size()) { return false; }

    bool ends = std::equal(suffix.rbegin(), suffix.rend(), orgStr.rbegin());
    return ends;
}

void CryptHandler::Decrypt(
    std::string relPath, 
    std::string key) {

}

void CryptHandler::Encrypt(
    std::string relPath, 
    std::string key) {

    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(relPath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG){ 
                std::string fPath = relPath + "/" + ent->d_name;

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
    }
}

void CryptHandler::GetDecryptedData(
    std::string encRaw, 
    std::string key) {

}

void CryptHandler::GetEncryptedData(
    std::string raw, 
    std::string key) {

}