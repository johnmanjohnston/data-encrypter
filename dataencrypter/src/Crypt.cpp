#include <iostream>
#include <fstream>
#include <dirent.h>
#include "../headers/Crypt.hpp"
#include "../headers/Utilscp.hpp"

// bool StrEndsWith(const std::string& orgstr, const std::string& suffix) {
//     size_t lStr = orgstr.length();
//     size_t lSuffix = suffix.length();

//     // if suffix is larger than string we desire to compare, it's not possible to return true  
//     // as the orginal string can't end with a string larger than itself
//     if (lSuffix > lStr) return false; 

//     return orgstr.compare(lStr - lSuffix, lSuffix, suffix) == 0;
// }

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