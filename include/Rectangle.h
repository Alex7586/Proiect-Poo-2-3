#pragma once
#ifndef RECTANGLE
#define RECTANGLE

#include "TwoDimensionalShape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Rectangle : public TwoDimensionalShape{
private:
	double width, height;
public:
	Rectangle();
	Rectangle(double _width, double _height);
	Rectangle(std::vector<std::pair<double, double>> _vertices);

	friend std::ostream& operator<<(std::ostream&, const Rectangle&);
	friend std::istream& operator>>(std::istream&, Rectangle&);

	void Afisare();

	double area();
	double perimeter();
	void display(sf::RenderWindow& window) const;

};

#endif
