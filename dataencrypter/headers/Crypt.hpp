#pragma once

#include <string>
#include <fstream>
#include <dirent.h>

    class CryptHandler {

        public:
            void Encrypt(           std::string relPath, std::string key);
            void Decrypt(           std::string relPath, std::string key);
            void WriteEncryptedData(std::string relPath, std::string key);
            void WriteDecryptedData(std::string relPath, std::string key);
    };
