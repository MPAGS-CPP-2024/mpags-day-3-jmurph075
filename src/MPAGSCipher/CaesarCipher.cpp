#include <CaesarCipher.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstddef>
CaesarCipher::CaesarCipher(const std::size_t key) : key_{key % alphabetSize_} {

}
// here we define our first constructor, just as any normal function
// here we initialise the key variable at definition
// for the constructor when the key is an unsigned integer (size_t),
// we initialise the variable by keeping it as is (the function is empty and does nothing to the key!)

//also use modulus function with alphabetSize_ (to give the remainder after division) in case we need to loop over
// as the key provided was too big!

// for the case when the key is a string :(,
// we define another constructor
// we go ahead and convert into an unsigned integer using the code copied from the main function
CaesarCipher::CaesarCipher(const std::string& key) : key_{0} 
// we set the default value of our data member within the class, i.e. key_ as 0 for now
// then we try and take the argument given, i.e. key, and get an integer from it
// after we do this, we can replace the 0 value with this new value.


{// We have the key as a string, but the Caesar cipher needs an unsigned long, so we first need to convert it
    // We default to having a key of 0, i.e. no encryption, if no key was provided on the command line
    if (!key.empty()) {
        // Before doing the conversion we should check that the string contains a
        // valid positive integer.
        // Here we do that by looping through each character and checking that it
        // is a digit. What is rather hard to check is whether the number is too
        // large to be represented by an unsigned long, so we've omitted that for
        // the time being.
        // (Since the conversion function std::stoul will throw an exception if the
        // string does not represent a valid unsigned long, we could check for and
        // handled that instead but we only cover exceptions very briefly on the
        // final day of this course - they are a very complex area of C++ that
        // could take an entire course on their own!)
        for (const auto& elem :key) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                    << "        the supplied key (" << key
                    << ") could not be successfully converted" << std::endl;
                return;
            }
        }
        key_ = std::stoul(key) % alphabetSize_; 
        // again in case the number given is too large and we want to loop back round
    }
}

//Now implement the constructor for the actual encryption of the cipher
// using the member function of the CaesarCipher class, applyCipher,
// and using the other data members, key_, alphabet_, and alphabetSize_,
// the same code as was in the RunCaesarCipher files previously, with the naming adjustments
std::string CaesarCipher::applyCipher(const std::string& inputText, const bool encrypt) const
{

    //Create the output string
    std::string outputText;

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize_; ++i) {
            if (origChar == alphabet_[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                if (encrypt) {
                    processedChar = alphabet_[(i + key_) % alphabetSize_];
                } else {
                    processedChar = alphabet_[(i + alphabetSize_ - key_) %
                                             alphabetSize_];
                }
                break;
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}
//Note that we cannot return out of a constructor!