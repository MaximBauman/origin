#include "Broom.h"

Broom::Broom() : AirTransport(20) {};
double Broom::AirReduce(double dist) const {
	int coeff = dist / 1000;
	return dist - ((dist / 100) * coeff);
}
std::string Broom::getType() const {
	return "Broom";
}
Broom::~Broom() = default;