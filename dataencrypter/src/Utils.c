#include <string.h>
#include <stdbool.h>
#include "../headers/Utils.h"

const char* VALIDATOR_PHRASE = "This file is required to validate your key! Don't tamper with this file.";

bool ValidateKey(const char* validatorFileData) {
    int matches = strcmp(validatorFileData, VALIDATOR_PHRASE) == 0;
    return matches == 1;
}