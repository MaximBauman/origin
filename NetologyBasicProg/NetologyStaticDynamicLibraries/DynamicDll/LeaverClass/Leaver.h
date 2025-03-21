
#pragma once
#include <iostream>

#ifdef LEAVERCLASSDYNAMIC_EXPORTS
#define LEAVERCLASS_API __declspec(dllexport)
#else
#define LEAVERCLASS_API __declspec(dllimport)
#endif // LEAVERDYNAMIC_EXPORTS


class Leaver {
public:
	LEAVERCLASS_API	void printerGoodbye(std::string);
};