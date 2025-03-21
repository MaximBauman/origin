#include "IncDec.h"
#include <iostream>



void Counter::set_counter(int num) { this->n_counter = num; };
void Counter::set_increment() { n_counter++; };
void Counter::set_decrement() { n_counter--; };
void Counter::get_actualValue() { std::cout << n_counter << std::endl; };