#pragma once

#include <string>
#include "mgdutils.h"

namespace ethyl {
    inline std::string read_file(const char* filepath)
    {
        FILE* file = fopen(filepath, "rt");
        fseek(file, 0, SEEK_END);
        unsigned long length = ftell(file);
        char* data = new char[length + (ulong)1]();
        fseek(file, 0, SEEK_SET);
        fread(data, 1, length, file);
        fclose(file);

        std::string result(data);
        delete[] data;
        return result;
    }
}

