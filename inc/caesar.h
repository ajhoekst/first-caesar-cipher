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
protected:
    ahio::file_map map_;
public:
    CaesarFile();
    CaesarFile(
        const char* filename
    );
    ~CaesarFile();
    std::size_t begin();
    std::size_t end();
    char& operator[](
        std::size_t index
    );
};

class CaesarRead : public CaesarFile
{
public:
    CaesarRead(
        const char* filename
    );
};

class CaesarWrite : public CaesarFile
{
public:
    CaesarWrite(
        const char* filename
    );
};
