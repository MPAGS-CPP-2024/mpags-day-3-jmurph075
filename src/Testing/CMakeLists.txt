# - Build sub-script for the MPAGSCipher library unit tests

# Most basic test (print hello world)
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# create interface library for catch
# this means we dont have to set a target_include_directories for each test program we add
# for it to find catch and perform the test
# users of the library simply "link" to it using target_link_libraries
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# First Catch-based test
# Build the executable program
add_executable(testCatch testCatch.cpp)
# ensure the Testing/ subdir is used to find Catch.hpp header
# so that the Catch tests can be performed
target_link_libraries(testCatch Catch)
# add the test itself (giving a name and providing the executable)
add_test(NAME test-catch COMMAND testCatch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)