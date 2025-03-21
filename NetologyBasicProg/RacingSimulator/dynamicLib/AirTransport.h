#pragma once

#include "Transport.h"

#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif

class AirTransport : public Transport {
public:
	DYNAMICLIB_API AirTransport(int);
	DYNAMICLIB_API double CalculateTime(double) const override;
	DYNAMICLIB_API virtual double AirReduce(double) const = 0;
	DYNAMICLIB_API virtual ~AirTransport() = default;

private:
	int speed;
};