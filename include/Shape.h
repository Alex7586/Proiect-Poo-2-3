#pragma once
#ifndef SHAPE
#define SHAPE

#include <SFML/Graphics.hpp>

class Shape {
private:
	
public:
	virtual void Afisare() = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual void display(sf::RenderWindow& window) const = 0;
};
#endif // !SHAPE
