#include "include/DartVMHelper.h"
#include <dart_api.h>
#include <iostream>

int InitSystem(char* param1)
{
    std::cout << param1 << " Starting Dart" << std::endl;

    auto buffer_ = reinterpret_cast<char*>(::malloc(64));

    free(buffer_);
    buffer_ = nullptr;

    std::cout << "Version " << Dart_VersionString() << std::endl;

    const char* where = "C:\\Develop\\flutter\\bin\\cache\\dart-sdk\\bin";
    auto result = Dart_SetVMFlags(1, &where); // Command Line
    if(result != nullptr) {
        std::cout << result << std::endl;
        return -1;
    }

    Dart_InitializeParams initParams;
    memset(&initParams, 0, sizeof(initParams));
    initParams.version = DART_INITIALIZE_PARAMS_CURRENT_VERSION;

    result = Dart_Initialize(&initParams);
    if(result != nullptr) {
        std::cout << result << std::endl;
        return -2;
    }

    std::cout << param1 << "Dart Started" << std::endl;
    return 0;
}

void DeinitSystem()
{
    auto result = Dart_Cleanup();
    if(result != nullptr) {
        std::cout << result << std::endl;
    }
    std::cout << "Dart Cleanup done" << std::endl;
}