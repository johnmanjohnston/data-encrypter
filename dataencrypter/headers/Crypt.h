// Responsible for the FILE HANDLING for crypting data

#pragma once

#include <string>
#include <fstream>
#include <dirent.h>

    class CryptHandler {

        public:
        // Crypts filedata and gets crypted data from other methods
            void Encrypt(std::string relPath,         std::string key);
            void Decrypt(std::string relPath,         std::string key);
     std::string GetDecryptedData(std::string encRaw, std::string key);
     std::string GetEncryptedData(std::string raw,    std::string key);
    };
