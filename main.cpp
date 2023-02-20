#include <iostream>

class Figure {
protected:
	std::string name;
	int sides_count;
	int a, b, c, d;
	int A, B, C, D;

public:
	Figure() {
		name = "Фигура";
		sides_count = 0;
	}
	int get_a() { return a; } int get_b() { return b; } int get_c() { return c; } int get_d() { return d; }
	int get_A() { return A; } int get_B() { return B; } int get_C() { return C; } int get_D() { return D; }
	std::string get_name() { return name; }
	int get_sides_count() { return sides_count; }
};

class Triangle : public Figure {
protected:
Triangle() : Triangle(a, b, c, A, B, C, sides_count) {

}
public:
     Triangle(int _a, int _b, int _c, int _A, int _B, int _C, int sides) {
        name = "Треугольник";
        sides_count = sides;
	    a = _a;
		b = _b;
		c = _c;
		A = _A;
		B = _b;
		C = _C;
     }
};

class Right : public Triangle {
public:

	Right(int C) : Triangle() {
        name = "Прямоугольный Треугольник";
	}
};

class Isosceles : public Triangle {
public:
	Isosceles(int a, int c, int C) : Triangle(a, b, c, A, B, C, sides_count) {
		name = "Равнобедренный Треугольник";
	}
};
class Equilateral : public Triangle {
public:
	Equilateral(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, sides_count) {
		name = "Равносторонний Треугольник";
	}
};

class Quadrangle :public Figure {
public:
	Quadrangle() {
		sides_count = 4;
		name = "Четырехугольник";
		a = 10, b = 20, c = 30, d = 40;
		A = 50, B = 60, C = 70, D = 80;
	}
};

class Rectangle : public Quadrangle {
public:
	Rectangle() {
		name = "Прямоугольник";
		a = 10, b = 20, c = 10, d = 20;
		A = 90, B = 90, C = 90, D = 90;
	}
};
class Square : public Rectangle {
public:
	Square() {
		name = "Квадрат";
		a = 20, c = 20;
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram() {
		name = "Параллелограмм";
		a = 20, b = 30, c = 20, d = 30;
		A = 30, B = 40, C = 30, D = 40;
	}
};

class Romb : public Parallelogram {
public:
	Romb() {
		name = "Ромб";
		a = 30, c = 30;
	}
};

void print_info(Figure* figure, int sides_count) {
	sides_count == 3 ?
		std::cout << figure->get_name() << ": " << std::endl
		<< "Стороны: " << "a = " << figure->get_a() << " b = " << figure->get_b() << " c = " << figure->get_c() << std::endl
		<< "Углы: " << " A = " << figure->get_A() << " B = " << figure->get_B() << " C = " << figure->get_C() << std::endl << std::endl
		: std::cout << figure->get_name() << ": " << std::endl
		<< "Стороны: " << "a = " << figure->get_a() << " b = " << figure->get_b() << " c = " << figure->get_c() << " d = " << figure->get_d() << std::endl
		<< "Углы: " << " A = " << figure->get_A() << " B = " << figure->get_B() << " C = " << figure->get_C() << " D = " << figure->get_D() << std::endl << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	Figure* triangle = new Triangle(10, 20, 30, 50, 60, 70, 3);
	print_info(triangle, triangle->get_sides_count());
	Figure* right = new Right(90);
	print_info(right, right->get_sides_count());
	Figure* isosceles = new Isosceles(10, 10, 50);
	print_info(isosceles, isosceles->get_sides_count());
	Figure* equilateral = new Equilateral(30, 30, 30, 60, 60, 60);
	print_info(equilateral, equilateral->get_sides_count());

	Figure* quadrangle = new Quadrangle;
	print_info(quadrangle, quadrangle->get_sides_count());
	Figure* rectangle = new Rectangle;
	print_info(rectangle, rectangle->get_sides_count());
	Figure* square = new Square;
	print_info(square, square->get_sides_count());
	Figure* parallelogramm = new Parallelogram;
	print_info(parallelogramm, parallelogramm->get_sides_count());
	Figure* romb = new Romb;
	print_info(romb, romb->get_sides_count());



	delete triangle;
	delete right;
	delete isosceles;
	delete equilateral;
	delete quadrangle;
	delete rectangle;
	delete square;
	delete parallelogramm;
	delete romb;
}