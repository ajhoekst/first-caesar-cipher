#pragma once

#include "file-mmap.h"

#include <iterator>

class CaesarCipher
{
private:
    int key_;
public:
    CaesarCipher(
        const int key
    );
    CaesarCipher(
        const char* arg
    );
    char encrypt(
        const char data
    );
    char decrypt(
        const char data
    );
};

class CaesarFile
{
private:
    ahio::file_map map_;
public:
    CaesarFile(
        const char* filename
    );
    std::size_t begin();
    std::size_t end();
    char operator[](
        std::size_t index
    );
};
