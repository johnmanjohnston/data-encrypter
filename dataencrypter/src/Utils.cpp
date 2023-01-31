#include "../headers/Utilscp.hpp"
#include <string>

bool StrEndsWith(const std::string& orgstr, const std::string& suffix) {
    size_t lStr = orgstr.length();
    size_t lSuffix = suffix.length();

    // if suffix is larger than string we desire to compare, it's not possible to return true  
    // as the orginal string can't end with a string larger than itself
    if (lSuffix > lStr) return false; 

    return orgstr.compare(lStr - lSuffix, lSuffix, suffix) == 0;
}