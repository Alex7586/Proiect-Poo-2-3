#include "../include/Triangle.h"

Triangle::Triangle() : TwoDimensionalShape() {}

Triangle::Triangle(std::vector<std::pair<double, double>> _vertices) :
	TwoDimensionalShape(_vertices) {}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
	os << "The triangle's vertices:\n";
	for (int i = 0; i < triangle.vertices.size(); i++) {
		os << "(" << triangle.vertices[i].first;
		os << ", " << triangle.vertices[i].second;
		os << ")\n";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Triangle& triangle) {
	double x, y;
	triangle.vertices.clear();

	std::cout << "The coordinates of the triangle:\n";
	for (int i = 0; i < 3; i++) {
		is >> x >> y;
		triangle.vertices.push_back(std::make_pair(x, y));
	}
	return is;
}

double Triangle::area() {
	std::pair<double, double> A = vertices[0];
	std::pair<double, double> B = vertices[1];
	std::pair<double, double> C = vertices[2];
	
	//heron
	double a = getDistance(B, C);
	double b = getDistance(A, C);
	double c = getDistance(A, B);
	double p = (a + b + c) / 2;

	return sqrt(p) * sqrt(p - a) * sqrt(p - b) * sqrt(p - c);
}

double Triangle::perimeter() {
	std::pair<double, double> A = vertices[0];
	std::pair<double, double> B = vertices[1];
	std::pair<double, double> C = vertices[2];
	double a = getDistance(B, C);
	double b = getDistance(A, C);
	double c = getDistance(A, B);
	return a + b + c;
}

void Triangle::Afisare() {
	std::cout << "The triangle's vertices:\n";
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << "(" << vertices[i].first;
		std::cout << ", " << vertices[i].second;
		std::cout << ")\n";
	}
}

void Triangle::display(sf::RenderWindow& window) const{
	sf::VertexArray shape(sf::LineStrip, 4);

	shape[0].position = sf::Vector2f(vertices[0].first * 10, -vertices[0].second * 10);
	shape[1].position = sf::Vector2f(vertices[1].first * 10, -vertices[1].second * 10);
	shape[2].position = sf::Vector2f(vertices[2].first * 10, -vertices[2].second * 10);
	shape[3].position = sf::Vector2f(vertices[0].first * 10, -vertices[0].second * 10);


	window.draw(shape);
}