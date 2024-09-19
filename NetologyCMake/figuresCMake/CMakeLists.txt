cmake_minimum_required(VERSION 3.20.0)
project(figures_cmake VERSION 1.0)

set(SOURCES
	ClassesHierarchy.cpp
	Basic.cpp
	Triangle.cpp
	Quadrangle.cpp
	EquilateralTriangle.cpp
	IsoscelesTriangle.cpp
	Rectangle.cpp
	Parallelogram.cpp
	Rhombus.cpp
	RightTriangle.cpp
	Square.cpp
)
set(HEADERS
	Basic.h
	Triangle.h
	Quadrangle.h
	EquilateralTriangle.h
	IsoscelesTriangle.h
	Rectangle.h
	Parallelogram.h
	Rhombus.h
	RightTriangle.h
	Square.h
)

add_executable(figures_cmake ${SOURCES} ${HEADERS})