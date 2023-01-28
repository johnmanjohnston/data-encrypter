#pragma once

#include <string>

    class CryptHandler {

        public:
        // Crypts filedata and gets crypted data from other methods
            void Encrypt(std::string raw,    std::string key);
            void Decrypt(std::string encRaw, std::string key);

            void GetDecryptedData(std::string encRaw, std::string key); // Made public for key validation

        private:
            void GetEncryptedData(std::string raw,    std::string key);
    };
