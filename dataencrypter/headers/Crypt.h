#pragma once

#include <string>
#include <fstream>

    class CryptHandler {

        public:
        // Crypts filedata and gets crypted data from other methods
            void Encrypt(std::string relPath,     std::string key);
            void Decrypt(std::string relPath,  std::string key);
            void GetDecryptedData(            std::string encRaw, std::string key);
            void GetEncryptedData(            std::string raw,    std::string key);
    };
