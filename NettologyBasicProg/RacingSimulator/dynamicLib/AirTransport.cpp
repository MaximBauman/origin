#include "AirTransport.h"

AirTransport::AirTransport(int speed) : speed(speed) {};

double AirTransport::CalculateTime(double distance) const {
	if (speed != 0) {
		double flyTime = this->AirReduce(distance) / speed;
		return flyTime;
	}
	else {
		return 0;
	}
}