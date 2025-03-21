#pragma once
#include <iostream>

#ifndef LEAVER_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif
class Leaver {
public:
	LEAVER_API	void printer(std::string);
};
