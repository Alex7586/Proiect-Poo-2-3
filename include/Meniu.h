#ifndef MENIU
#define MENIU

#include "TwoDimensionalShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ThreeDimensionalShape.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Sphere.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum choices {
	DISPLAY = 1,
	VISUAL_DISPLAY,
	AREA_2D,
	PERIMETER_2D,
	SURFACE_AREA,
	PERIMETER_3D,
	VOLUME,
	DISTANCE_2D,
	DISTANCE_3D,
	CLOSE
};

enum shape2d {
	triangle = 1,
	rectangle,
	circle,
	other2D
};

enum shape3d {
	cuboid,
	cylinder,
	cone,
	sphere,
	other3d
};

class Meniu {
private:
	bool closed = false;
	static Meniu* instance;
	Meniu() {}

public:
	Meniu(const Meniu&) = delete;
	Meniu& operator=(const Meniu&) = delete;

	static Meniu* GetInstance() {
		if (instance == nullptr) {
			instance = new Meniu();
		}
		return instance;
	}

	bool Close();
	void Afisare();
	void Alegere(std::vector<Shape<double>*>& shapes);

private:
	void display(std::vector<Shape<double>*> shapes);
	void displayVisual(std::vector<Shape<double>*> shapes);
	void area2d();
	void perimeter2d();
	void surfaceArea();
	void perimeter3d();
	void volume();
	void distance2d();
	void distance3d();
};

#endif // !MENIU
