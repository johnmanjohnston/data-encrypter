#include <iostream>
#include <fstream>
#include <dirent.h>
#include "../headers/Crypt.hpp"
#include "../headers/Utilscp.hpp"

void CryptHandler::Decrypt(
    std::string relPath, 
    std::string key) {

    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(relPath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG){ 
                std::string fPath = relPath + "/" + ent->d_name;

                if (StrEndsWith(fPath, ".enc")) { 
                    WriteDecryptedData(fPath, relPath, key);
                } else { continue; }
            }
        }

        CleanupDir(dir);
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

                if (StrEndsWith(fPath, ".enc")) { continue; } // Skip already encrypted files
                WriteEncryptedData(fPath, relPath, key);
            }
        }

        CleanupDir(dir);
    } else {
        std::cout << "Couldn't open dir :/\n";
    }
}

// We use the OpenSSL CLI for cryption, these are the commands we try to replicate
// To encrypt:
// openssl aes-256-cbc -a -salt -pbkdf2 -in infile.txt -out outfile.txt.enc
// To decrypt
// openssl aes-256-cbc -d -a -pbkdf2 -in infile.txt.enc -out outfile.txt.new

void CryptHandler::WriteEncryptedData(
    std::string relfPath, std::string relDirPath, std::string key) {

    std::string runCommand;
    runCommand += "openssl aes-256-cbc -a -salt -pbkdf2 -in ";
    runCommand += relfPath;
    runCommand += " -out ";
    runCommand += relfPath + ".enc"; // Append to the encrypted filename so we can see the enrypted form
    runCommand += " -k ";
    runCommand += key;

    system(runCommand.c_str());
}   

void CryptHandler::WriteDecryptedData(
    std::string relfPath, std::string relDirPath, std::string key) {

    std::string runCommand;
    runCommand += "openssl aes-256-cbc -d -a -pbkdf2 -in ";
    runCommand += relfPath; // Do NOT append ".enc" as we're only scanning for the encrypted files in Encrypt()
    runCommand += " -out ";
    runCommand += relfPath + ".decrypted";
    runCommand += " -k ";
    runCommand += key;
    
    system(runCommand.c_str());;
}