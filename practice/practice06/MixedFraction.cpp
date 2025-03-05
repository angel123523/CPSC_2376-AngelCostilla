#include "MixedFraction.h"

MixedFraction::MixedFraction(int whole, int n, int d) :Fraction(n, d), wholePart(whole) {}
MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
	wholePart = GetNumerator() / getDenominator();
	int newNumerator = GetNumerator() % getDenominator();
	setNumerator(newNumerator);
}
std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction) {
	if (mixedFraction.wholePart != 0) {
		os << mixedFraction.wholePart << "";
	}
	os << mixedFraction.GetNumerator() << "/" << mixedFraction.getDenominator();
	return os;
}