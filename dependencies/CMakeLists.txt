FetchContent_Declare(libdartshared 
    GIT_REPOSITORY    https://github.com/DerKleinePunk/dart_shared_libray.git
    GIT_TAG           "V0.0.1"
)

message("Fetching libdartshared...")

message("Build for Type ${CMAKE_BUILD_TYPE}")

FetchContent_MakeAvailable(libdartshared)