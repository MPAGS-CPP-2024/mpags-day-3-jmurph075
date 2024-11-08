# - Build sub-script for the MPAGSCipher library

# - Declare the build of the static MPAGSCipher library
# - specify that we want the library to be static (other type is shared)
# - static libraries have to be built and linked into the executable whereas 
# - shared libraries are 'referenced' and shipped as separate files

# - Then list all the sources that should be compiled to create the library
# - This is just all the other MPAGSCipher files
# - Note that RunCaesarCipher files are now redundant so not included here!
add_library(MPAGSCipher STATIC
    CipherMode.hpp
    CaesarCipher.hpp
    CaesarCipher.cpp
    ProcessCommandLine.hpp
    ProcessCommandLine.cpp
    TransformChar.hpp
    TransformChar.cpp
)   

# - Just like we did for the other CMakeLists.txt for the mpags-cipher executable
# - we declare the needed C++ features and header search paths for MPAGSCipher
# - This time we declare the features and paths using the PUBLIC scope specificier
# - This is because we will have mpags-cipher as a client of the library, 
# - so it needs to know about these

target_include_directories(MPAGSCipher
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(MPAGSCipher
  PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization
)