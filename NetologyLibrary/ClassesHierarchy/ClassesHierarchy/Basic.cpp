#include "Basic.h"

void Basic::print_info() {}
std::string Basic::get_name() const { return name_; };
Basic::Basic(std::string name) : name_(name) {}
