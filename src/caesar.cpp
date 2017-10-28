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

CaesarFile::CaesarFile()
{
    map_.length = 0;
}

CaesarFile::CaesarFile(
    const char* filename
)
{
    ahio::map_file(
        &map_,
        filename,
        FILE_MAP_RW_SHARED
    );
}

CaesarFile::~CaesarFile()
{
    ahio::unmap_file( &map_ );
}

std::size_t CaesarFile::begin()
{
    return 0;
}

std::size_t CaesarFile::end()
{
    return map_.length;
}

char& CaesarFile::operator[](
    std::size_t index
)
{
    return ((char*) map_.address)[index];
}

CaesarRead::CaesarRead(
    const char* filename
) : CaesarFile()
{
    ahio::map_file(
        &map_,
        filename,
        FILE_MAP_R_SHARED
    );
}

CaesarWrite::CaesarWrite(
    const char* filename,
    std::size_t maxBytes
) : CaesarFile()
{
    map_.length = maxBytes;
    ahio::map_file(
        &map_,
        filename,
        FILE_MAP_W_SHARED
    );
}

void CaesarWrite::operator()(
    const std::size_t& index,
    const char& data
)
{
    ((char*) map_.address)[index] = data;
}
