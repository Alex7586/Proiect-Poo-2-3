#pragma once
#ifndef SHAPE
#define SHAPE

#include <SFML/Graphics.hpp>

template<class T>
class Shape {
private:
	
public:
	virtual void Afisare() = 0;
	virtual T area() = 0;
	virtual T perimeter() = 0;
	virtual void display(sf::RenderWindow& window) const = 0;
};
#endif // !SHAPE
