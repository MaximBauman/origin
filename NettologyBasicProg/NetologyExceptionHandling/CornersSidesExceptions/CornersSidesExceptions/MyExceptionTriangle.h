#pragma once
#include <iostream>
class MyExceptionTriangle : public std::exception {
public:
	const char* what() const override;

};
