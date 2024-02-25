FetchContent_Declare(libdartshared 
    GIT_REPOSITORY    https://github.com/DerKleinePunk/dart_shared_libray.git
    GIT_TAG           "v0.0.9"
)

message("Fetching libdartshared...")

message("Build for Type ${CMAKE_BUILD_TYPE}")

set(BUILD_SMAPLES OFF)
FetchContent_MakeAvailable(libdartshared)

MESSAGE(STATUS "libdartshared source ${libdartshared_SOURCE_DIR}")

set(libsource_SRCS ${libdartshared_SOURCE_DIR} PARENT_SCOPE)