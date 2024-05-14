#pragma once
#ifndef TRIANGLE
#define TRIANGLE

#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape {
public:
	Triangle();
	Triangle(std::vector<std::pair<double, double>> _vertices);

	friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
	friend std::istream& operator>>(std::istream& is, Triangle& triangle);

	void Afisare();

	double area();
	double perimeter();
	void display(sf::RenderWindow& window) const;
};

#endif