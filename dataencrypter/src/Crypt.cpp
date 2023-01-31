#include <iostream>
#include <fstream>
#include <dirent.h>
#include "../headers/Crypt.hpp"
#include "../headers/Utilscp.hpp"

std::string CryptValidationFilename = ".crypt-validation.txt";

void CryptHandler::Decrypt(
    std::string relPath, 
    std::string key) {

    DIR* dir;
    struct dirent* ent;
    bool validKey = false;

    if ((dir = opendir(relPath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG){ 
                std::string fPath = relPath + "/" + ent->d_name;

                if (StrEndsWith(fPath, CryptValidationFilename)) { 
                    // Validate key
                    continue;
                }

                if (validKey) {
                    std::ofstream wfstream(fPath);
                    wfstream << key;
                    wfstream.close();
                } else {
                    std::cout << "Invalid key";
                }
            }
        }

        closedir(dir);
    } else {
        std::cout << "Couldn't open dir :/\n";
    }
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

                if (StrEndsWith(fPath, CryptValidationFilename)) { continue; }

                std::ofstream wfstream(fPath);
                wfstream << key;
                wfstream.close();
            }
        }

        closedir(dir);
    } else {
        std::cout << "Couldn't open dir :/\n";
    }
}

std::string CryptHandler::GetDecryptedData(
    std::string encRaw, 
    std::string key) {
        return "";
}

std::string CryptHandler::GetEncryptedData(
    std::string raw, 
    std::string key) {
        return "";

}