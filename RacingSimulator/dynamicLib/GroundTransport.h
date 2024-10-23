#pragma once
#include "Transport.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class GroundTransport : public Transport {
public:
	DYNAMICLIB_API GroundTransport(int, double, double, double, double);
	DYNAMICLIB_API double CalculateTime(double) const override;
	DYNAMICLIB_API virtual ~GroundTransport() = default;
private:
	int speed;
	double timeToRelax;
	double relaxTime;
	double relaxTime_2;
	double relaxTime_3;
};