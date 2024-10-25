#include "Carpet.h"

Carpet::Carpet() : AirTransport(10) {};

double Carpet::AirReduce(double dist) const {
	if (dist < 1000) {
		return dist;
	}
	else if (1000 <= dist < 5000) {
		return dist * 0.97;
	}
	else if (5000 <= dist < 10000) {
		return dist * 0.9;
	}
	else {
		return dist * 0.95;
	}
}

std::string Carpet::getType() const {
	return "Carpet";
}

Carpet::~Carpet() = default;