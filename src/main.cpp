#define __ahio

#include "caesar.h"

#include <iostream>

int main(
    int argc,
    char** argv
)
{
    // Forward declarations
    std::size_t index;

    // Load input message
    CaesarFile message( argv[1] );

    // Create cipher
    CaesarCipher cipher( argv[2] );

    // Print encrypted input message
    std::cout << "Encrypted message:" << std::endl;
    for (
        index = message.begin();
        index != message.end();
        index++
    )
    {
       printf("%c", cipher.encrypt(message[index]));
    }
    std::cout << std::endl;

    // Print decrypted input message
    std::cout << "Decrypted message:" << std::endl;
    for (
        index = message.begin();
        index < message.end();
        index++
    )
    {
       printf("%c", cipher.decrypt(message[index]));
    }
    std::cout << std::endl;

    return 0;
}