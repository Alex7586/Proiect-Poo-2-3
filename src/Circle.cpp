#include "../include/Circle.h"
const double Circle::PI = 3.141592653589;

Circle::Circle() : TwoDimensionalShape(), radius{ 0 }, precision{ 50 } {}

Circle::Circle(double xCenter, double yCenter, double _radius, int _precision) : center{ std::make_pair(xCenter,yCenter) },
	radius{ _radius }, precision{ _precision } {}

std::ostream& operator<<(std::ostream& os, const Circle& circle) {
	os << "The circle have: ";
	os << "\ncenter: (" << circle.center.first << ", " << circle.center.second << ")";
	os << "\nradius: " << circle.radius;
	return os;
}

std::istream& operator>>(std::istream& is, Circle& circle) {
	std::cout << "Coordinates of the center: ";
	is >> circle.center.first >> circle.center.second;
	std::cout << "Radius: ";
	is >> circle.radius;
	return is;
}

double Circle::getRadius() const {
	return radius;
}

double Circle::area() {
	return PI * radius * radius;
}

double Circle::perimeter() {
	return 2 * PI * radius;
}

void Circle::Afisare() {
	std::cout << "The circle have: ";
	std::cout << "\ncenter: (" << center.first << ", " << center.second << ")";
	std::cout << "\nradius: " << radius;
}

void Circle::display(sf::RenderWindow& window) const {
	sf::CircleShape circle(radius*10);

	circle.setOrigin(radius*10, radius*10);
	circle.setPosition(sf::Vector2f(center.first, -center.second));
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(1.f);

	window.draw(circle);
}