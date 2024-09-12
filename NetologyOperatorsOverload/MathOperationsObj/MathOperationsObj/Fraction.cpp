#include "Fraction.h"
#include <string>

Fraction::Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
	if (denominator_ == 0) {
		throw "Can't create with denominator = 0!";
	}
};

std::string Fraction::print() {
	std::string fraction = std::to_string(numerator_) + "/" + std::to_string(denominator_);
	return fraction;
}

Fraction Fraction::operator+ (Fraction right) {
	int num = numerator_ * right.denominator_ + right.numerator_ * denominator_;
	int den = denominator_ * right.denominator_;
	return Fraction(num, den);
};
Fraction Fraction::operator- (Fraction right) {
	int num = numerator_ * right.denominator_ - right.numerator_ * denominator_;
	int den = denominator_ * right.denominator_;
	return Fraction(num, den);
};
Fraction Fraction::operator* (Fraction right) {
	int num = numerator_ * right.numerator_;
	int den = denominator_ * right.denominator_;
	return Fraction(num, den);
};
Fraction Fraction::operator/ (Fraction right) {
	int num = numerator_ * right.denominator_;
	int den = denominator_ * right.numerator_;
	return Fraction(num, den);
};
Fraction Fraction::operator- () {
	return Fraction(-numerator_, denominator_);
};
Fraction Fraction::operator++ () {
	numerator_ = numerator_ + denominator_;
	return Fraction(numerator_, denominator_);
};
Fraction Fraction::operator++(int) {
	numerator_ = numerator_ + denominator_;
	return Fraction(numerator_, denominator_);

};
Fraction Fraction::operator-- () {
	numerator_ = numerator_ - denominator_;
	return Fraction(numerator_, denominator_);

}
	
Fraction Fraction::operator--(int) {
	numerator_ = numerator_ - denominator_;
	return Fraction(numerator_, denominator_);

};





//bool Fraction::operator== (Fraction right) const {
//	return (numerator_ * right.denominator_) / (denominator_ * right.denominator_) == (right.numerator_ * denominator_) / (denominator_ * right.denominator_);
//}
//bool Fraction::operator!= (Fraction right) const {
//	return (numerator_ * right.denominator_) / (denominator_ * right.denominator_) != (right.numerator_ * denominator_) / (denominator_ * right.denominator_);
//}
//bool Fraction::operator< (Fraction right) const {
//	return (numerator_ * right.denominator_) / (denominator_ * right.denominator_) < (right.numerator_ * denominator_) / (denominator_ * right.denominator_);
//}
//bool Fraction::operator> (Fraction right) const {
//	return (numerator_ * right.denominator_) / (denominator_ * right.denominator_) > (right.numerator_ * denominator_) / (denominator_ * right.denominator_);
//}
//bool Fraction::operator<= (Fraction right) const {
//	return (numerator_ * right.denominator_) / (denominator_ * right.denominator_) <= (right.numerator_ * denominator_) / (denominator_ * right.denominator_);
//}
//bool Fraction::operator>= (Fraction right) const {
//	return (numerator_ * right.denominator_) / (denominator_ * right.denominator_) >= (right.numerator_ * denominator_) / (denominator_ * right.denominator_);
//}