#pragma once
class Counter
{
public:
	Counter() : n_counter(1) {};

	void set_counter(int num);
	void set_increment();
	void set_decrement();
	void get_actualValue();
private:
	int n_counter;
};