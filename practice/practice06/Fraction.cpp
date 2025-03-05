#include "Fraction.h"

Fraction::Fraction() : num(0), den(1) {}
Fraction::Fraction(int n, int d) {
	if (d == 0) throw std::invalid_argument("denominator cannot be zero.");
	num = n;
	den = d;
	simplify();
}
int Fraction::GetNumerator() const {
	return num;
}
int Fraction::getDenominator() const {
	return den;
}
void Fraction::setNumerator(int n) {
	num = n;
	simplify();
}
void Fraction::setDenominator(int d) {
	if (d==0) throw std::invalid_argument("denominator cannot be zero.");
	den = d;
	simplify();
}
void Fraction::simplify() {
	if (den == 0) throw std::invalid_argument("denominater cannot be zero");
	int a = num;
	int b = den;

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	int gcd = a;
	num /= gcd;
	den /= gcd;
	if (den < 0) {
		num = -num;
		den = -den;
	}
}
Fraction operator+(const Fraction & lhs, const Fraction& rhs) {
	int numerator = lhs.num * rhs.den + rhs.num * lhs.den;
	int denominator = lhs.den * rhs.den;
	return Fraction(numerator, denominator);
}
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	int numerator = lhs.num * rhs.den - rhs.num * lhs.den;
	int denominator = lhs.den * rhs.den;
	return Fraction(numerator, denominator);
}
Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	int numerator = lhs.num * rhs.num;
	int denominator = lhs.den * rhs.den;
	return Fraction(numerator, denominator);
}
Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	if (rhs.num == 0) throw std::invalid_argument("cannot divide by zero");
	int numerator = lhs.num * rhs.den;
	int denominator = lhs.den * rhs.num;
	return Fraction(numerator, denominator);
}
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
	os << fraction.num << "/" << fraction.den;
	return os;
}