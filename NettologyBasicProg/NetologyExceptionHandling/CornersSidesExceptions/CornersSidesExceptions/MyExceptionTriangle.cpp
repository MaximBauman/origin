#include "MyExceptionTriangle.h"


const char* MyExceptionTriangle::what() const {
	return "TriangleBug";
};