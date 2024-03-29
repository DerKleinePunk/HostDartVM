#include "include/DartVMHelper.h"
#include <dart_dll.h>
#include <include/dart_api.h>
#include <iostream>

int InitSystem(char* param1)
{
    std::cout << param1 << " Starting Dart" << std::endl;
    std::cout << "Version " << Dart_VersionString() << std::endl;

    // Initialize Dart
    DartDllConfig config;
    config.service_port = 6222;

    if (!DartDll_Initialize(config)) {
        return -1;
    }

    std::cout << param1 << "Dart Started" << std::endl;
    return 0;
}

void DeinitSystem()
{
    DartDll_Shutdown();
    std::cout << "Dart Cleanup done" << std::endl;
}