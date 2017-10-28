#define __ahio

#include "caesar.h"

#include "file-mmap.h"

CaesarCipher::CaesarCipher(
    const int key
) : key_(key)
{
}

CaesarCipher::CaesarCipher(
    const char* arg
)
{
    key_ = atoi(arg);
}

char CaesarCipher::encrypt(
    const char data
)
{
    return data + key_;
}

char CaesarCipher::decrypt(
    const char data
)
{
    return data - key_;
}

CaesarFile::CaesarFile(
    const char* filename
)
{
    ahio::map_file(
        &map_,
        filename,
        FILE_MAP_R_PRIVATE
    );
}

std::size_t CaesarFile::begin()
{
    return 0;
}

std::size_t CaesarFile::end()
{
    return map_.length;
}

char CaesarFile::operator[](
    std::size_t index
)
{
    return ((char*) map_.address)[index];
}
