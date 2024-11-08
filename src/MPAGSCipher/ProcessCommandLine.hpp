#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include <cctype>

#include "CipherMode.hpp"
//so we can specify encrypt/decrypt

// can create a new type (a struct) called ProgramSettings containing all the command line info
struct ProgramSettings {
    // indicates presence of help flag in the args
    bool helpRequested;
    // indicates presence of version flag in args
    bool versionRequested;
    // name of input file
    std::string inputFile;
    // name of output file
    std::string outputFile;
    // key to be used in encrypt/decrypt routine
    std::string cipherKey;
    // flag indicating whether cipher should encrypt or decrypt 
    CipherMode cipherMode;
};

// can now group this struct into an arg for the processCommandLine function so that both appear in the header
bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        ProgramSettings& settings);
// pass args by reference (&) as will want to change them
#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP