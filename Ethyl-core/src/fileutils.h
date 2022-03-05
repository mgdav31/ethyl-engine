#pragma once
#pragma warning( disable : 26451 ) // [length + 1] gives arithmetic overflow

#include <string>
#include "mgdutils.h"

namespace ethyl {
    inline std::string read_file(const char* filepath)
    {
        FILE* file = fopen(filepath, "rt");
        fseek(file, 0, SEEK_END);
        unsigned long length = ftell(file);
        char* data = new char[length + 1]();
        fseek(file, 0, SEEK_SET);
        fread(data, 1, length, file);
        fclose(file);

        std::string result(data);
        delete[] data;
        return result;
    }
}

