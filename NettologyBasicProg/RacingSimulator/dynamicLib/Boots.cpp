#include "Boots.h"

Boots::Boots() : GroundTransport(6, 60, 10, 5, 5) {};

std::string Boots::getType() const {
	return "Boots";
}

Boots::~Boots() = default;