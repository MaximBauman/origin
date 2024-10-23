#pragma once
#include "GroundTransport.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Boots : public GroundTransport {
public:
	DYNAMICLIB_API Boots();
	DYNAMICLIB_API std::string getType() const override;
	DYNAMICLIB_API ~Boots();
};