#pragma once
#include <iostream>

#include <vector>
#include "Race.h"
#include "Boots.h"
#include "Broom.h"
#include "Camel.h"
#include "Carpet.h"
#include "Eagle.h"
#include "FastestCamel.h"
#include "Kentaur.h"
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif
DYNAMICLIB_API int RaceTypes();

DYNAMICLIB_API double distanceLog();

DYNAMICLIB_API int regMenu(Race&, std::vector<std::string>);
DYNAMICLIB_API int subRegMenu(int, int, Race&, std::vector<std::string>);
DYNAMICLIB_API int regBlock(int, int, int, Race&, std::vector<std::string>&, Boots&, Broom&, Camel&, Kentaur&, Eagle&, FastestCamel&, Carpet&);