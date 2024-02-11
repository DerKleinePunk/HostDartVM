project("SimpleTest" CXX)

# Pass information about version to C++ code through header
#    that will be supplemented by cmake.
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.h"
)

file(GLOB SOURCES "*.cpp" "*/*.cpp")

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(SimpleTest ${SOURCES})

if (MSVC)
  set_property(TARGET SimpleTest PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  target_compile_definitions(DartVMHelper PUBLIC UNICODE _UNICODE)
  set_target_properties( SimpleTest PROPERTIES VS_PLATFORM_TOOLSET v142 )
endif()

# Demo application require both libraries, so add them
target_link_libraries(SimpleTest DartVMHelper)

# Point to which directory Demo is copied during installation and packaging
install(TARGETS SimpleTest DESTINATION SimpleTest)

