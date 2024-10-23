#pragma once
#include "Transport.h"
#include <iostream>
#include <vector>
#include <algorithm>
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Race {
public:
	DYNAMICLIB_API Race(double dist);
	DYNAMICLIB_API void addTransport(Transport* vehicle);
	DYNAMICLIB_API void startRace();
	DYNAMICLIB_API void cleaner();
	DYNAMICLIB_API ~Race();
private:
	double raceDistance;
	std::vector<Transport*> vehicles;
};