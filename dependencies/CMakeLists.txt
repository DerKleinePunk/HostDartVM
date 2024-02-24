FetchContent_Declare(libdartshared 
    GIT_REPOSITORY    https://github.com/DerKleinePunk/dart_shared_libray.git
    GIT_TAG           "v0.0.2"
)

message("Fetching libdartshared...")

message("Build for Type ${CMAKE_BUILD_TYPE}")

FetchContent_MakeAvailable(libdartshared)