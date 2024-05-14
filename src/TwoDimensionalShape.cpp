#include "../include/TwoDimensionalShape.h"

TwoDimensionalShape::TwoDimensionalShape() {
	vertices.push_back(std::make_pair(0,0));
}

TwoDimensionalShape::TwoDimensionalShape(std::vector<std::pair<double, double>> _vertices) {
	vertices = _vertices;
	vertices.push_back(vertices[0]);
}

std::ostream& operator<<(std::ostream& os, const TwoDimensionalShape& twoDShape) {
	os << "Your shape's vertices in plane:\n";
	for (int i = 0; i < twoDShape.vertices.size(); i++) {
		os << "(" << twoDShape.vertices[i].first << ", " << twoDShape.vertices[i].second << ")\n";
	}
	return os;
}

std::istream& operator>>(std::istream& is, TwoDimensionalShape& twoDShape) {
	int n;
	is >> n;
	twoDShape.vertices.clear();
	for (int i = 0; i < n; i++) {
		double x, y;
		is >> x >> y;
		twoDShape.vertices.push_back(std::make_pair(x, y));
	}
	twoDShape.vertices.push_back(twoDShape.vertices[0]);
	return is;
}

double TwoDimensionalShape::area() {
	double A = 0;
	double xAnt = vertices[0].first, yAnt = vertices[0].second;
	for (int i = 1; i < vertices.size(); i++) {
		double x = vertices[i].first, y = vertices[i].second;
		A = A + (-x * yAnt + y * xAnt);
		xAnt = x;
		yAnt = y;
	}
	return A / 2;
}

double TwoDimensionalShape::perimeter() {
	double P = 0;
	std::pair<double,double> prevVertex = vertices[0];
	for (int i = 1; i < vertices.size(); i++) {
		P += distance(prevVertex, vertices[i]);
		prevVertex = vertices[i];
	}
	return P;
}

double TwoDimensionalShape::distance(std::pair<double, double> A, std::pair<double, double> B) {
	return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}

double TwoDimensionalShape::getDistance(std::pair<double, double> A, std::pair<double, double> B) {
	return distance(A,B);
}

void TwoDimensionalShape::Afisare() {
	std::cout  << "Your shape's vertices in plane:\n";
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")\n";
	}
}

void TwoDimensionalShape::display(sf::RenderWindow& window) const {
	sf::VertexArray shape(sf::LineStrip,vertices.size());

	for (int i = 0; i < vertices.size(); i++) {
		shape[i] = sf::Vertex(sf::Vector2f(vertices[i].first * 10, -vertices[i].second * 10));
	}

	window.draw(shape);
}