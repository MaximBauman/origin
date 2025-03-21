#pragma once
#include "AirTransport.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Eagle : public AirTransport {
public:
	DYNAMICLIB_API Eagle();
	DYNAMICLIB_API double AirReduce(double) const override;
	DYNAMICLIB_API std::string getType() const override;
	DYNAMICLIB_API ~Eagle();
};