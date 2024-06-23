#pragma once
#ifndef THRDIMSHAPE
#define THRDIMSHAPE

#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

class ThreeDimensionalShape : public Shape<double> {
private:
	std::vector<int> numberVerticesFaces;
protected:
	std::vector<std::tuple<double, double, double>> vertices;
public:
	ThreeDimensionalShape();
	ThreeDimensionalShape(std::vector<std::tuple<double, double, double>> _vertices, std::vector<int> _numberVerticesFaces);

	friend std::ostream& operator<<(std::ostream& os, const ThreeDimensionalShape& threeDShape);
	friend std::istream& operator>>(std::istream& is, ThreeDimensionalShape& threeDShape);

	template<class T>
	static T getDistance(std::tuple<double, double, double> A, std::tuple<double, double, double> B);

	virtual void Afisare();

	virtual double area();
	virtual double perimeter();
	virtual double volume();
	virtual void display(sf::RenderWindow& window) const;
private:
	template<class T>
	static T distance(std::tuple<double, double, double> A, std::tuple<double, double, double> B);
};

#endif