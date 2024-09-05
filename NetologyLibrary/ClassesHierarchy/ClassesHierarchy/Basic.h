#pragma once
#include <iostream>
class Basic
{
public:
    Basic(std::string);
    virtual void print_info();
    virtual ~Basic();
    std::string get_name() const;
private:
    std::string name_;
};