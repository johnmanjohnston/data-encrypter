#pragma once

#include <string>

    class CryptHandler {

        public:
        // Crypts filedata and gets crypted data from private methods
            void Encrypt(std::string raw,    std::string key);
            void Decrypt(std::string encRaw, std::string key);

        private:
            void GetDecryptedData(std::string encRaw,    std::string key);
            void GetEncryptedData(std::string raw,    std::string key);
    };
