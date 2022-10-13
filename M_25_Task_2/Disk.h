#pragma once

#include <fstream>
#include "Ram.h"

bool save(int* buf, int size_buf, const char* path);

bool load(int* buf, const char* path);
