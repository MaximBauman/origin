#pragma once
#include "AirTransport.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Broom : public AirTransport {
public:
	DYNAMICLIB_API Broom();
	DYNAMICLIB_API double AirReduce(double) const override;
	DYNAMICLIB_API std::string getType() const override;
	DYNAMICLIB_API ~Broom();
};