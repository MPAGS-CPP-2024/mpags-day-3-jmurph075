#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>
#include <cctype>
#include <cstddef> // need this to include std::size_t type
class CaesarCipher {
  public:
 // create a new caesarcipher with the given key
    explicit CaesarCipher(const std::size_t key); // the constructor which sets the initial state of object;
    // the constructor just has the key as its sole argument
    //note that std::size_t is the type which is produced from the size of an object. 
    //std::string::size() returns a size_t
    //std::vector::size() returns a size_t
    // it gives an "unsigned integer"
    
    explicit CaesarCipher(const std::string& key); // second constructor declared
    // in the case the key is given as a string
    // pass this by reference (don't know why)

    //now want to add a member FUNCTION that encrypts/decrypts 
    // a string and returns the resulting string
    //using the data member key above

    std::string applyCipher(const std::string& inputText, const bool encrypt) const;

  private:

    // introduce an alphabet vector data member
    // and an alphabet size data member for the case when we need to loop back round
    const std::vector<char> alphabet_ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const std::size_t alphabetSize_{alphabet_.size()};

    std::size_t key_{0}; // this is the key data member variable of the class

    // both of these are now private
    


};

#endif //MPAGSCIPHER_CAESARCIPHER_HPP