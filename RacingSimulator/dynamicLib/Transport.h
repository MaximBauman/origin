#pragma once

#include <iostream>
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Transport {
public:
	DYNAMICLIB_API virtual ~Transport() = default;
	DYNAMICLIB_API virtual double CalculateTime(double distance) const = 0;
	DYNAMICLIB_API virtual std::string getType() const = 0;
private:
	int speed;
	std::string type;
	std::string name;
};