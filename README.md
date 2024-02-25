# This is an Test Projekt to Host an Dart VM and Run User Code in the C# Webservice

## Building

please read README.md from Dart Dynamic Import Library Auto Build Current not Work
CMake say lib not found wenn SDK ist not build
Im search for Solution without command on Console from user...

```bash
cd ./build/_deps/libdartshared-src
cd ./scripts/build_helpers
dart pub get
cd ../..
dart ./scripts/build_helpers/bin/build_dart.dart -v -tall
```

XCOPY D:\Projects\Privat\dart-sdk\*.* D:\Projects\Privat\HostDartVM\build\_deps\libdartshared-src\dart-sdk /S /E /C /H /R /Y /D