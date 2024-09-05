#include "Basic.h"

Basic::Basic(std::string name) : name_(name) {}
void Basic::print_info() {}
std::string Basic::get_name() const { return name_; };
Basic::~Basic() { };

