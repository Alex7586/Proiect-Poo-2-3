#include "../include/Cone.h"
const double Cone::PI = 3.141592653589;

Cone::Cone() : ThreeDimensionalShape() {}

Cone::Cone(Circle _base, double _height) : ThreeDimensionalShape(), base{ _base }, height{ _height } {}

std::ostream& operator<<(std::ostream& os, const Cone& cone) {
	os << "Your cone:\nThe base:\n";
	os << cone.base;
	os << "The height: " << cone.height;
	return os;
}

std::istream& operator>>(std::istream& is, Cone& cone) {
	std::cout << "The base:\n";
	is >> cone.base;
	std::cout << "The height:\n";
	is >> cone.height;
	return is;
}

double Cone::area() {
	return PI * base.getRadius() * (base.getRadius() + sqrt(pow(base.getRadius(), 2) + pow(height, 2)));
}

double Cone::perimeter() {
	return base.perimeter();
}

double Cone::volume() {
	return base.area() * height / 3;
}

void Cone::Afisare() {
	std::cout << "Your cone:\nThe base:\n";
	std::cout << base;
	std::cout << "The height: " << height;
}

void Cone::display(sf::RenderWindow& window) const {}