#include <iostream>
#include <string>
#include <filesystem>
#include <iostream>
#include "../headers/Common.h"

using namespace std;

// Define globals
std::string RelativeDir;
int main() {
    std::cout << "Main.cpp working";
    std::cin >> RelativeDir;

    for (const auto & entry : filesystem::directory_iterator(RelativeDir))
        std::cout << entry.path() << std::endl;
    
    return 0;
}