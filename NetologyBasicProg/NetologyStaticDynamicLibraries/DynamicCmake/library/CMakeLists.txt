# library/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyLibrary)

add_library(Leaver SHARED Leaver.h Leaver.cpp)

# Установите экспорт всех символов (для Windows)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
