#ifndef MPAGSCIPHER_CIPHERMODE_HPP
#define MPAGSCIPHER_CIPHERMODE_HPP

#include <string>
#include <vector>
#include <cctype>
#include <cstddef>

// make a header file containing an enumeration to designate the encryption mode
// then after we include this header file elsewhere in our program we can
// then use this instead of the "encrypt" boolean flag in the rest of our code

enum class CipherMode{
    Encrypt, // applies cipher in encrypt mode
    Decrypt  // applies cipher in decrypt mode
};

#endif //MPAGSCIPHER_CIPHERMODE_HPP