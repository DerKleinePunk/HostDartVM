cmake_minimum_required(VERSION 3.8.2) # 3.8.0 is minimum version that allow Linux remote building and debugging
project("DartVMHelper" CXX)

FIND_PACKAGE(DartApi REQUIRED)



# Remove trailing '\' and '/' at the end of the path, so can reliably compare
STRING(REGEX REPLACE "[/\\]+$" "" CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})
STRING(REGEX REPLACE "[/\\]+$" "" CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# When compiling DLib as stand alone library set to C++11,
# when library is part of other project, respect parent project settings.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	# Enforce c++11 standard.
	set (CMAKE_CXX_STANDARD 11)
endif()

# Notification when too low version of C++ is set
if(NOT DEFINED CMAKE_CXX_STANDARD OR CMAKE_CXX_STANDARD LESS 11)
	message(FATAL_ERROR "ERROR: CMAKE_CXX_STANDARD is not set or it is too low. Minimum C++ v11 is required to compile \"DartHostVM\" library.")
endif()
   
file (GLOB SOURCES "*.cpp" "*/*.cpp")


INCLUDE_DIRECTORIES(${DARTAPI_INCLUDE_DIR})
add_library(DartVMHelper SHARED ${SOURCES})

TARGET_LINK_LIBRARIES(DartVMHelper PRIVATE ${DARTAPI_LIBRARY})
if (MSVC)
  set_property(TARGET DartVMHelper PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  target_compile_definitions(DartVMHelper PUBLIC UNICODE _UNICODE)
  target_compile_definitions(DartVMHelper PUBLIC _USRDLL)
endif()
set_target_properties(DartVMHelper PROPERTIES PUBLIC_HEADER include/DartVMHelper.h)
target_include_directories(DartVMHelper PUBLIC ${CMAKE_BINARY_DIR}/exports)


include (GenerateExportHeader)
GENERATE_EXPORT_HEADER (DartVMHelper
    BASE_NAME DartVMHelper
    EXPORT_MACRO_NAME DECLSPEC
    EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/DartVMHelper_Export.h
    STATIC_DEFINE DartVMHelper_BUILT_AS_STATIC
)

MESSAGE(STATUS "Build DartVMHelper")

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories(DartVMHelper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (MSVC)
  set_property(TARGET DartVMHelper PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  set_target_properties( DartVMHelper PROPERTIES VS_PLATFORM_TOOLSET v142 )
endif()

# List files that install and/or package should provide.
# Each library should know what it want to distribute,
# which files are internal or intermediate and which are public library export.
install(TARGETS DartVMHelper DESTINATION DartHostVM-bin)
install(FILES DartVMHelper.h DESTINATION DartHostVM-include)