#define __ahio

#include "caesar.h"

#include "file-mmap.h"

#include <iostream>

int main(
    int argc,
    char** argv
)
{
    ahio::file_map m;
    ahio::map_file(
        &m,
        argv[1],
        FILE_MAP_R_PRIVATE
    );
    printf("File contents:\n%s\n", m.address);
    ahio::unmap_file( &m );

    return 0;
}
