#pragma once
#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int, int);

	Fraction operator+ (Fraction right) ;
	Fraction operator- (Fraction right) ;
	Fraction operator* (Fraction right) ;
	Fraction operator/ (Fraction right) ;
	Fraction operator- ();
	Fraction operator++ ();
	Fraction operator++(int);
	Fraction operator-- ();
	Fraction operator--(int);
	std::string print();
	std::string operator= (Fraction);

	//bool operator== (Fraction right) const;
//bool operator!= (Fraction right) const;
//bool operator< (Fraction right) const;
//bool operator> (Fraction right) const;
//bool operator<= (Fraction right) const;
//bool operator>= (Fraction right) const;
};