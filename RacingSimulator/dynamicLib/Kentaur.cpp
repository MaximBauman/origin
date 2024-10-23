#include "Kentaur.h"

Kentaur::Kentaur() : GroundTransport(15, 8, 2, 2, 2) {};

std::string Kentaur::getType() const {
	return "Kentaur";
}
Kentaur::~Kentaur() = default;