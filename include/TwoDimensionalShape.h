#pragma once
#ifndef TWODIMSHAPE
#define TWODIMSHAPE

#include "Shape.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class TwoDimensionalShape : public Shape<double> {
protected:
	std::vector<std::pair<double, double>> vertices;
public:
	TwoDimensionalShape();
	TwoDimensionalShape(std::vector<std::pair<double, double>> _vertices);

	friend std::ostream& operator<<(std::ostream& os, const TwoDimensionalShape& twoDShape);
	friend std::istream& operator>>(std::istream& is, TwoDimensionalShape& twoDShape);

	virtual void Afisare() override; 

	virtual double area();
	virtual double perimeter();

	static double getDistance(std::pair<double, double> A, std::pair<double, double> B);
	virtual void display(sf::RenderWindow& window) const;
private:
	static double distance(std::pair<double, double> A, std::pair<double, double> B);
};

#endif // !TWODIMSHAPE
