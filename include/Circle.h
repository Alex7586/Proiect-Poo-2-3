#pragma once
#ifndef CIRCLE
#define CIRCLE

#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape {
private:
	int precision; //number of vertices that makes the circle
	std::pair<double, double> center;
	double radius;
	static const double PI;
public:
	Circle();
	Circle(double xCenter, double yCenter, double _radius = 0, int _precision = 50);

	friend std::ostream& operator<<(std::ostream&, const Circle&);
	friend std::istream& operator>>(std::istream&, Circle&);

	double getRadius() const;

	void Afisare();
	
	double area();
	double perimeter();
	void display(sf::RenderWindow& window) const;
};

#endif