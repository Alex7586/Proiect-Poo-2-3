#include "../include/Sphere.h"
const double Sphere::PI = 3.141592653589;

Sphere::Sphere() : ThreeDimensionalShape() {}

Sphere::Sphere(double _radius) : ThreeDimensionalShape(), radius{ _radius } {}

std::ostream& operator<<(std::ostream& os, const Sphere& sphere) {
	os << "Your sphere:\nThe radius: ";
	os << sphere.radius;
	return os;
}

std::istream& operator>>(std::istream& is, Sphere& sphere) {
	std::cout << "The radius: ";
	is >> sphere.radius;
	return is;
}

double Sphere::area() {
	return 4 * PI * radius * radius;
}


double Sphere::volume() {
	return area() * radius / 3;
}

void Sphere::Afisare() {
	std::cout << "Your sphere:\nThe radius: ";
	std::cout << radius;
}

void Sphere::display(sf::RenderWindow& window) const {}