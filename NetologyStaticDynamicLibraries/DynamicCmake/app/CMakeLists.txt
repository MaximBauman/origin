# app/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyApp)

add_executable(MyApp GoodbyeSol.cpp)

# ������� ���� � ����������
include_directories(../library)

# ��������� ���������� � �����������
target_link_libraries(MyApp PRIVATE Leaver)
