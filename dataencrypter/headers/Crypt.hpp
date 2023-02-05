#pragma once

#include <string>

    class CryptHandler {

        public:
            void            Encrypt(std::string relPath,                          std::string key);
            void            Decrypt(std::string relPath,                          std::string key);
            void WriteEncryptedData(std::string relfPath, std::string relDirPath, std::string key);
            void WriteDecryptedData(std::string relfPath, std::string relDirPath, std::string key);
    };
