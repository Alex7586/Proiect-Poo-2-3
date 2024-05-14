#pragma once
#ifndef SPHERE
#define SHPERE

#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape {
private:
	double radius;
	static const double PI;
public:
	Sphere();
	Sphere(double _radius);

	friend std::ostream& operator<<(std::ostream& os, const Sphere& sphere);
	friend std::istream& operator>>(std::istream& is, Sphere& sphere);

	void Afisare();

	double area();
	double volume();
	void display(sf::RenderWindow& window) const;
};

#endif