#include <string.h>
#include <stdbool.h>
#include "../headers/Utils.h"

const char* ValidationPhrase = "This file is required to validate your key! Don't tamper with this file.";

bool ValidateKey(const char* validatorFileData) {
    int matches = strcmp(validatorFileData, ValidationPhrase) == 0;
    return matches == 1;
}