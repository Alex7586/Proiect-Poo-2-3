#ifndef CONE
#define CONE

#include "ThreeDimensionalShape.h"
#include "Circle.h"

class Cone : public ThreeDimensionalShape {
private:
	Circle base;
	double height;
	static const double PI;
public:
	Cone();
	Cone(Circle _base, double _height);

	friend std::ostream& operator<<(std::ostream& os, const Cone& cone);
	friend std::istream& operator>>(std::istream& is, Cone& cone);

	void Afisare();

	double area();
	double perimeter();
	double volume();
	void display(sf::RenderWindow& window) const;
};

#endif