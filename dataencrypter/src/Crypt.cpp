#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <dirent.h>
#include "../headers/Crypt.hpp"
#include "../headers/Utilscp.hpp"


std::string CryptValidationFilename = ".crypt-validation.txt";


void CryptHandler::Decrypt(
    std::string relPath, 
    std::string key) {

    WriteDecryptedData("../demo/a.txt", relPath, key);
    return;

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

    WriteEncryptedData("../demo/a.txt", relPath, key);
    return;


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

void CryptHandler::WriteEncryptedData(
    std::string relfPath, std::string relDirPath, std::string key) {

    std::cout << "relfPath: " << relfPath;

    // openssl aes-256-cbc -a -salt -pbkdf2 -in secrets.txt -out secrets.txt.enc
    // openssl aes-256-cbc -d -a -pbkdf2 -in secrets.txt.enc -out secrets.txt.new

    std::string runCommand;
    runCommand += "openssl aes-256-cbc -a -salt -pbkdf2 -in ";
    runCommand += relfPath;
    runCommand += " -out ";
    runCommand += relfPath + ".enc";
    runCommand += " -k ";
    runCommand += key;
    system(runCommand.c_str());
}   

void CryptHandler::WriteDecryptedData(
    std::string relfPath, std::string relDirPath, std::string key) {

    // Decryption returns empty; needs fix!
    std::cout << "relfPath: " << relfPath;

    std::string runCommand;
    runCommand += "openssl aes-256-cbc -d -a -pbkdf2 -in ";
    runCommand += relfPath + ".enc";
    runCommand += " -out ";
    runCommand += relfPath + ".decrypted.new";
    runCommand += " -k ";
    runCommand += key;
    system(runCommand.c_str());;
}