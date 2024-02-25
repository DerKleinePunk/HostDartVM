cmake_minimum_required(VERSION 3.8.2) # 3.8.0 is minimum version that allow Linux remote building and debugging
project(DartVMHelper)


# Enforce c++11 standard.
set (CMAKE_CXX_STANDARD 11)


# The version number.
set(Example_VERSION_MAJOR 0)
set(Example_VERSION_MINOR 0)
set(Example_VERSION_PATCH 1)

SET (MAINFOLDER ${PROJECT_SOURCE_DIR})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

#Build Cmake Environment
SET(PKG_CONFIG_USE_CMAKE_PREFIX_PATH TRUE)
find_package(PkgConfig)
include(CheckCXXCompilerFlag)
include(FetchContent)

SET (EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
SET (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/bin")
SET (LIBS_DIR ${PROJECT_SOURCE_DIR}/libs/${TARGET})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS )

MESSAGE(STATUS "Build to ${EXECUTABLE_OUTPUT_PATH}")

ADD_SUBDIRECTORY(dependencies)
SET (DART_DIR "${libsource_SRCS}/dart-sdk/sdk")
ADD_SUBDIRECTORY(src)

# USE_FOLDERS group cmake generated projects into one (CMakePredefinedTargets) folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Below line set Demo as startup application in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SimpleTest)


# Add installer (it is called CPack) which brings all files together (.exe, .lib, .dll, and .h) and put into one file 
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${MAINFOLDER}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR ${Example_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${Example_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${Example_VERSION_PATCH})
include(CPack)
