#include "../include/Cylinder.h"
const double Cylinder::PI = 3.141592653589;

Cylinder::Cylinder() : ThreeDimensionalShape() {}

Cylinder::Cylinder(Circle _base, double _height) : ThreeDimensionalShape(), base{ _base }, height{ _height } {}

std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder) {
	os << "Your cylinder:\nThe base:\n";
	os << cylinder.base;
	os << "The height: " << cylinder.height;
	return os;
}

std::istream& operator>>(std::istream& is, Cylinder& cylinder) {
	std::cout << "The base:\n";
	is >> cylinder.base;
	std::cout << "The height:\n";
	is >> cylinder.height;
	return is;
}

double Cylinder::area() {
	return 2 * PI * base.getRadius() * (base.getRadius() + height);
}

double Cylinder::perimeter() {
	return 2 * base.perimeter();
}

double Cylinder::volume() {
	return base.area() * height;
}

void Cylinder::Afisare() {
	std::cout << "Your cylinder:\nThe base:\n";
	std::cout << base;
	std::cout << "The height: " << height;
}

void Cylinder::display(sf::RenderWindow& window) const {}