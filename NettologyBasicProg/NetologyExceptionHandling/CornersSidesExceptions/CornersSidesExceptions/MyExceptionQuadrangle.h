#pragma once
#include <iostream>

class MyExceptionQuadrangle : public std::exception {
public:
	const char* what() const override;
};