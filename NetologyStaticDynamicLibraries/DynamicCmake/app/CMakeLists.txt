# app/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyApp)

add_executable(MyApp GoodbyeSol.cpp)

# ”кажите путь к библиотеке
include_directories(../library)

# —в€зываем приложение с библиотекой
target_link_libraries(MyApp PRIVATE Leaver)
