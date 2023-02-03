#include "../headers/Utilscp.hpp"
#include <string>

bool StrEndsWith(const std::string& orgstr, const std::string& suffix) {
    // if suffix is larger than string we desire to compare, it's not possible to return true  
    // as the orginal string can't end with a string larger than itself
    if (suffix.length() > orgstr.length()) return false; 
    return orgstr.compare(orgstr.length() - suffix.length(), suffix.length(), suffix) == 0;
}
