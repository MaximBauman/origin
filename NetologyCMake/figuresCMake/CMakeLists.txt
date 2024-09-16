cmake_minimum_required(VERSION 3.20.0)
project(figures_cmake VERSION 1.0)

add_library(src_files Basic.cpp EquilateralTriangle.cpp IsoscelesTriangle.cpp Parallelogram.cpp Quadrangle.cpp Rectangle.cpp Rhombus.cpp RightTriangle.cpp Square.cpp Triangle.cpp)

add_executable(figures_cmake ClassesHierarchy.cpp)

target_link_libraries(figures_cmake src_files)