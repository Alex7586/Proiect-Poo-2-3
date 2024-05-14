#pragma once
#ifndef CUBOID
#define CUBOID

#include "ThreeDimensionalShape.h"

class Cuboid : public ThreeDimensionalShape {
private:
	double length, breadth, height;
public:
	Cuboid();
	Cuboid(double _length, double _breadth, double _height);

	friend std::ostream& operator<<(std::ostream& os, const Cuboid& cuboid);
	friend std::istream& operator>>(std::istream& is, Cuboid& cuboid);

	void Afisare();

	virtual double area();
	virtual double perimeter();
	virtual double volume();
	void display(sf::RenderWindow& window) const;
};

#endif // !CUBOID
