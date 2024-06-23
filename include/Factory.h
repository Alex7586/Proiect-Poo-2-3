#ifndef FACTORY
#define FACTORY

#include "TwoDimensionalShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Shape.h"
#include <vector>

class Creator2d {
public:
	virtual Shape<double>* FactoryMethod(std::vector<std::pair<double, double>> _vertices) = 0;
	virtual Shape<double>* FactoryMethod(double xCenter, double yCenter, double _radius, int _precision = 50) = 0;
	virtual Shape<double>* FactoryMethod(double _width, double _height) = 0;
	virtual ~Creator2d() {};
};

class CreatorTriunghi : public Creator2d {
public:
	Shape<double>* FactoryMethod(std::vector<std::pair<double, double>> _vertices) override {
		return new Triangle(_vertices);
	}

	Shape<double>* FactoryMethod(double xCenter, double yCenter, double _radius = 0, int _precision = 50) override {}
	Shape<double>* FactoryMethod(double _width, double _height) override {};
};

class CreatorCerc : public Creator2d {
public:
	Shape<double>* FactoryMethod(double xCenter, double yCenter, double _radius = 0, int _precision = 50) override {
		return new Circle(xCenter, yCenter, _radius, _precision);
	}

	Shape<double>* FactoryMethod(double _width, double _height) override {}
	Shape<double>* FactoryMethod(std::vector<std::pair<double, double>> _vertices) override {}
};

class CreatorRectangle : public Creator2d {
public:
	Shape<double>* FactoryMethod(double _width, double _height) override {
		return new Rectangle(_width, _height);
	}

	Shape<double>* FactoryMethod(std::vector<std::pair<double, double>> _vertices) override {
		return new Rectangle(_vertices);
	}

	Shape<double>* FactoryMethod(double xCenter, double yCenter, double _radius = 0, int _precision = 50) override {}
};

#endif