#include "../include/ThreeDimensionalShape.h"

ThreeDimensionalShape::ThreeDimensionalShape() {
	vertices.push_back(std::make_tuple(0, 0, 0));
}

ThreeDimensionalShape::ThreeDimensionalShape(std::vector<std::tuple<double, double, double>> _vertices,
	std::vector<int> _numberVerticesFaces) : vertices{ _vertices }, numberVerticesFaces(_numberVerticesFaces){};

std::ostream& operator<<(std::ostream& os, const ThreeDimensionalShape& threeDShape) {
	os << "Your shape has " << threeDShape.numberVerticesFaces.size() << " faces\n";
	for (int i = 0; i < threeDShape.numberVerticesFaces.size(); i++) {
		os << "Face " << i + 1 << ":\n";
		os << "Your face's vertices are:\n";
		for (int j = 0; j < threeDShape.vertices.size(); j++) {
			os << "(" << std::get<0>(threeDShape.vertices[j]) << ", ";
			os << std::get<1>(threeDShape.vertices[j]) << ", ";
			os << std::get<2>(threeDShape.vertices[j]) << ")\n";
		}
		os << '\n';
	}
	return os;
}

std::istream& operator>>(std::istream& is, ThreeDimensionalShape& threeDShape) {
	int n,nrVert;
	std::cout << "Number of faces: ";
	is >> n;
	threeDShape.vertices.clear();
	threeDShape.numberVerticesFaces.clear();
	for (int j = 0; j < n; j++) {
		std::cout << "Number of vertices of face " << j + 1 << ":";
		is >> nrVert;
		threeDShape.numberVerticesFaces.push_back(nrVert);
		int aux = threeDShape.vertices.size();
		std::cout << "Coordinates of the face " << j+1 << ":\n";
		for (int i = 0; i < nrVert; i++) {
			double x, y, z;
			is >> x >> y >> z;
			threeDShape.vertices.push_back(std::make_tuple(x, y, z));
		}
		threeDShape.vertices.push_back(threeDShape.vertices[aux]);
	}
	return is;
}

double ThreeDimensionalShape::area() {
	double A = 0;
	int j = 0;
	for (int i = 0; i < numberVerticesFaces.size(); i++) {
		std::tuple<double, double, double> O = vertices[j];
		for (; j < numberVerticesFaces[i]; j++) {
			std::tuple<double, double, double> M = vertices[j];
			std::tuple<double, double, double> N = vertices[j + 1];

			double a = distance<double>(N, O);
			double b = distance<double>(M, O);
			double c = distance<double>(M, N);
			double p = (a + b + c) / 2;

			A += sqrt(p) * sqrt(p - a) * sqrt(p - b) * sqrt(p - c);
		}
		j++;
	}
	return A;
}

double ThreeDimensionalShape::perimeter() {
	double P = 0;
	int j = 0;
	for (int i = 0; i < numberVerticesFaces.size(); i++) {
		for (; j < numberVerticesFaces[i]; j++) {
			P += distance<double>(vertices[j], vertices[j + 1]);
		}
		j++;
	}
	return P / 2;
}

double ThreeDimensionalShape::volume() {
	return 0;
}

template<class T>
T ThreeDimensionalShape::distance(std::tuple<double, double, double> A, std::tuple<double, double, double> B) {
	return sqrt(pow(std::get<0>(A) - std::get<0>(B), 2) + pow(std::get<1>(A) - std::get<1>(B), 2) + pow(std::get<2>(A) - std::get<2>(B), 2));
}

template<class T>
T ThreeDimensionalShape::getDistance(std::tuple<double, double, double> A, std::tuple<double, double, double> B) {
	return distance<T>(A, B);
}

void ThreeDimensionalShape::Afisare() {
	std::cout << "Your shape has " << numberVerticesFaces.size() << " faces\n";
	for (int i = 0; i < numberVerticesFaces.size(); i++) {
		std::cout << "Face " << i + 1 << ":\n";
		std::cout << "Your face's vertices are:\n";
		for (int j = 0; j < vertices.size(); j++) {
			std::cout << "(" << std::get<0>(vertices[j]) << ", ";
			std::cout << std::get<1>(vertices[j]) << ", ";
			std::cout << std::get<2>(vertices[j]) << ")\n";
		}
		std::cout << '\n';
	}
}

void ThreeDimensionalShape::display(sf::RenderWindow& window) const {}

template double ThreeDimensionalShape::distance<double>(std::tuple<double, double, double> A, std::tuple<double, double, double> B);
template int ThreeDimensionalShape::distance<int>(std::tuple<double, double, double> A, std::tuple<double, double, double> B);
template double ThreeDimensionalShape::getDistance<double>(std::tuple<double, double, double> A, std::tuple<double, double, double> B);
template int ThreeDimensionalShape::getDistance<int>(std::tuple<double, double, double> A, std::tuple<double, double, double> B);