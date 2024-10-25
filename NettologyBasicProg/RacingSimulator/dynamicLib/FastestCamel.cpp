#include "FastestCamel.h"

FastestCamel::FastestCamel() : GroundTransport(40, 10, 5, 6.5, 8) {};
std::string FastestCamel::getType() const {
	return "FastestCamel";
}
FastestCamel::~FastestCamel() = default;