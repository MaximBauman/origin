#include "MyExceptionQuadrangle.h"

const char* MyExceptionQuadrangle::what() const {
	return "can't create quadrangle";
}