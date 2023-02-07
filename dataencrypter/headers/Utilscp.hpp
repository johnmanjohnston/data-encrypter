#pragma once

#include <string>
#include <dirent.h>

bool StrEndsWith(const std::string& orgstr, const std::string& suffix);
void CleanupDir(DIR* &usedDir);