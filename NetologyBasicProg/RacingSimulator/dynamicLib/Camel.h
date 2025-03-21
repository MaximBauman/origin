#pragma once
#include "GroundTransport.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Camel : public GroundTransport {
public:
	DYNAMICLIB_API Camel();
	DYNAMICLIB_API std::string getType() const override;
	DYNAMICLIB_API ~Camel();
};