#pragma once
#include "GroundTransport.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
class Kentaur : public GroundTransport {
public:
	DYNAMICLIB_API Kentaur();
	DYNAMICLIB_API std::string getType() const override;
	DYNAMICLIB_API ~Kentaur();
};