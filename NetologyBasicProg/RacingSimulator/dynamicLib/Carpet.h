#pragma once
#include "AirTransport.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Carpet : public AirTransport {
public:
	DYNAMICLIB_API Carpet();
	DYNAMICLIB_API double AirReduce(double) const override;
	DYNAMICLIB_API std::string getType() const override;
	DYNAMICLIB_API ~Carpet();
};