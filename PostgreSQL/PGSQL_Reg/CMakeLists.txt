cmake_minimum_required(VERSION 3.12)
project(PGSQL_Reg)

set(CMAKE_CXX_STANDARD 20)

find_package(PostgreSQL REQUIRED)
find_package(libpqxx CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE PostgreSQL::PostgreSQL libpqxx::pqxx)

#In CmakePresets set link to vcpkg.cmake