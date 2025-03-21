#include <iostream>

#include "Fraction.h"

int main()
{
	int num_1, num_2, den_1, den_2;

	std::cout << "Input numerator 1: ";
	std::cin >> num_1;
	std::cout << std::endl;
	std::cout << "Input denominator 1: ";
	std::cin >> den_1;
	std::cout << std::endl;
	std::cout << "Input numerator 2: ";
	std::cin >> num_2;
	std::cout << std::endl;
	std::cout << "Input denominator 2: ";
	std::cin >> den_2;
	std::cout << std::endl;

	Fraction f1(num_1, den_1);
	Fraction f2(num_2, den_2);
	Fraction sum = f1 + f2;
	Fraction min = f1 - f2;
	Fraction mult = f1 * f2;
	Fraction dev = f1 / f2;

	std::cout << "You entered two fractions: " << std::endl;
	std::cout << f1.print() << " " << f2.print() << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||Math operations|||||||||||||||||||||||||||||||||" << std::endl;

	std::cout << f1.print() << " + " << f2.print() << " = " << sum.print() << std::endl;
	std::cout << f1.print() << " - " << f2.print() << " = " << min.print() << std::endl;
	std::cout << f1.print() << " * " << f2.print() << " = " << mult.print() << std::endl;
	std::cout << f1.print() << " / " << f2.print() << " = " << dev.print() << std::endl;
	Fraction unar = -f1;
	std::cout << "Unary operator - : " << unar.print() << std::endl;
	Fraction incrPost = f2++;
	std::cout << "Postfix increment: " << incrPost.print() << std::endl;
	Fraction incrPref = ++f2;
	std::cout << "Prefix increment: " << incrPref.print() << std::endl;
	Fraction decPost = f1--;
	std::cout << "Postfix decrement: " << decPost.print() << std::endl;
	Fraction decPref = --f1;
	std::cout << "Prefix decrement: " << decPref.print() << std::endl;






	//Fraction f1(4, 3);
	//Fraction f2(6, 11);
	//std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	//std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	//std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	//std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	//std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	//std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
