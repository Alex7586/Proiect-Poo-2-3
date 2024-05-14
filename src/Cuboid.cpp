#include "../include/Cuboid.h"

Cuboid::Cuboid() : ThreeDimensionalShape() {}

Cuboid::Cuboid(double _L, double _l, double _h) : ThreeDimensionalShape(), 
	length{ _L }, breadth{ _l }, height{ _h } {}

std::ostream& operator<<(std::ostream& os, const Cuboid& cuboid) {
	os << "Your cuboid:";
	os << "\nLength: " << cuboid.length;
	os << "\nBreadth: " << cuboid.breadth;
	os << "\nHeight: " << cuboid.height;
	return os;
}

std::istream& operator>>(std::istream& is, Cuboid& cuboid) {
	std::cout << "Length: ";
	is >> cuboid.length;
	std::cout << "Breadth: "; 
	is >> cuboid.breadth;
	std::cout << "Height: "; 
	is >> cuboid.height;
	return is;
}

double Cuboid::area() {
	return 2 * (length * breadth + length * height + breadth * height);
}

double Cuboid::perimeter() {
	return 4 * (length + breadth + height);
}

double Cuboid::volume() {
	return length * breadth * height;
}

void Cuboid::Afisare() {
	std::cout << "Your cuboid:";
	std::cout << "\nLength: " << length;
	std::cout << "\nBreadth: " << breadth;
	std::cout << "\nHeight: " << height;
}

void Cuboid::display(sf::RenderWindow& window) const {}