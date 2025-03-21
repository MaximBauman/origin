#include "GroundTransport.h"

GroundTransport::GroundTransport(int speed, double timetorelax, double relaxtime, double relaxtime2, double relaxtime3) : speed(speed), timeToRelax(timetorelax), relaxTime(relaxtime), relaxTime_2(relaxtime2), relaxTime_3(relaxtime3) {};
double GroundTransport::CalculateTime(double distance) const {
	double travelTime = distance / speed;
	int relaxPeriods = travelTime / timeToRelax;
	if (relaxPeriods == 0) {
		return travelTime;
	}
	else if (relaxPeriods == 1) {
		return travelTime += relaxTime;
	}
	else if (relaxPeriods == 2) {
		return travelTime += relaxTime + relaxTime_2;
	}
	else {
		return travelTime += relaxTime + relaxTime_2 + relaxTime_3 * (relaxPeriods - 2);
	}
}