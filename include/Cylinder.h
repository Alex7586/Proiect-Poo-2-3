#ifndef CYLINDER
#define CYLINDER

#include "ThreeDimensionalShape.h"
#include "Circle.h"

class Cylinder : public ThreeDimensionalShape {
private:
	Circle base;
	double height;
	static const double PI;
public:
	Cylinder();
	Cylinder(Circle _base, double _height);

	friend std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder);
	friend std::istream& operator>>(std::istream& is, Cylinder& cylinder);

	void Afisare();

	double area();
	double perimeter();
	double volume();
	void display(sf::RenderWindow& window) const;
};

#endif