#include "Eagle.h"

Eagle::Eagle() : AirTransport(8) {};

double Eagle::AirReduce(double dist) const {
	return dist * 0.94;
}

std::string Eagle::getType() const {
	return "Eagle";
}
Eagle::~Eagle() = default;