#include "../include/Rectangle.h"

Rectangle::Rectangle() : TwoDimensionalShape(), width{ 0 }, height{ 0 } {}

Rectangle::Rectangle(double _width, double _height)
	:TwoDimensionalShape({ std::make_pair(0,0),
							std::make_pair(_width,0),
							std::make_pair(_width,_height),
							std::make_pair(0,_height) }),
	width{ _width }, height{ _height } {}

Rectangle::Rectangle(std::vector<std::pair<double, double>> _vertices) : TwoDimensionalShape(_vertices) {
	//sqrt(pow(x - xAnt, 2) + pow(y - yAnt, 2))
	std::pair<double,double> A = _vertices[0], B = _vertices[1], C = _vertices[2];
	width = getDistance(A,B);
	height = getDistance(B,C);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) {
	os << "The rectangle has:";
	os << "\nwidth = " << rectangle.width;
	os << "\nheight = " << rectangle.height;
	os << "\nCoordonates in plane:";
	for (int i = 0; i < rectangle.vertices.size(); i++) {
		os << "(" << rectangle.vertices[i].first << ", " << rectangle.vertices[i].second << ")\n";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
	std::cout << "Your rectangle coordinates:\n";
	rectangle.vertices.clear();
	for (int i = 0; i < 4; i++) {
		double x, y;
		is >> x >> y;
		rectangle.vertices.push_back(std::make_pair(x, y));
	}
	rectangle.width = TwoDimensionalShape::getDistance(rectangle.vertices[0],rectangle.vertices[1]);
	rectangle.height = TwoDimensionalShape::getDistance(rectangle.vertices[1], rectangle.vertices[2]);
	rectangle.vertices.push_back(rectangle.vertices[0]);
	return is;
}

double Rectangle::area() {
	return width * height; 
}

double Rectangle::perimeter() {
	return 2 * (width + height);
}

void Rectangle::Afisare() {
	std::cout << "The rectangle has:";
	std::cout << "\nWidth = " << width;
	std::cout << "\nHeight = " << height;
	std::cout << "\nCoordonates in plane:";
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")\n";
	}
}

void Rectangle::display(sf::RenderWindow& window) const {
	sf::VertexArray shape(sf::LineStrip, 5);

	shape[0].position = sf::Vector2f(vertices[0].first * 10, -vertices[0].second * 10);
	shape[1].position = sf::Vector2f(vertices[1].first * 10, -vertices[1].second * 10);
	shape[2].position = sf::Vector2f(vertices[2].first * 10, -vertices[2].second * 10);
	shape[3].position = sf::Vector2f(vertices[3].first * 10, -vertices[3].second * 10);
	shape[4].position = sf::Vector2f(vertices[0].first * 10, -vertices[0].second * 10);

	window.draw(shape);
}