#pragma once
#include "RaceType.h"

class GroundRace : public RaceType {
public: 
	GroundRace();
	int TimeSpend(int, int) override;
};