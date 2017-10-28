#define __ahio

#include "caesar.h"

int main(
    int argc,
    char** argv
)
{
    // Forward declarations
    std::size_t index;

    // Load input message
    CaesarRead message( argv[1] );

    // Prepare output message
    CaesarWrite encrypted(
        argv[2],
        message.end()
    );

    // Create cipher
    CaesarCipher cipher( argv[3] );

    // Print encrypted input message
    for (
        index = message.begin();
        index != message.end();
        index++
    )
    {
        encrypted(index, cipher.encrypt(message[index]));
    }

    return 0;
}
