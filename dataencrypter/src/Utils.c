#include <string.h>
#include <stdbool.h>
#include "../headers/Utils.h"

// When your file data is encrypted, and you call the function to decrypt your file data,
// We have to make sure the key used is correct to revert files to their orginal form
// Otherwise the file data will be lost. To do this, we haev a ValidationPhrase which will be used to 
// see if the decrypted data of the .crypt-validation.txt file matches
const char* ValidationPhrase = "This file is required to validate your key! Don't tamper with this file.";

bool ValidateKey(const char* validatorFileData) {
    int matches = strcmp(validatorFileData, ValidationPhrase) == 0;
    return matches == 1;
}