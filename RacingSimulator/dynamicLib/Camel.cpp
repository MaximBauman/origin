#include "Camel.h"

Camel::Camel() : GroundTransport(10, 30, 5, 8, 8) {}
std::string Camel::getType() const {
	return "Camel";
}
Camel::~Camel() = default;