#include <iostream>

class Figure {
protected:
	std::string name;
	int sides_count;
	int a, b, c, d;
	int A, B, C, D;
	Figure(std::string name, int sides_count, int a, int b, int c, int d, int A, int B, int C, int D){
		this->name = name;
		this->sides_count = sides_count;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
public:
	Figure() : Figure("Фигура", 0, 0, 0, 0, 0, 0, 0, 0, 0){}
	int get_a() { return a; } int get_b() { return b; } int get_c() { return c; } int get_d() { return d; }
	int get_A() { return A; } int get_B() { return B; } int get_C() { return C; } int get_D() { return D; }
	std::string get_name() { return name; }
	int get_sides_count() { return sides_count; }
};

class Triangle : public Figure {
protected:
	Triangle(std::string name, int sides_count, int a, int b, int c, int A, int B, int C): Figure(name, 3, a, b, c, d, A, B, C, D){}
public:
	Triangle(std::string name, int a, int b, int c, int A, int B, int C) : Triangle(name, sides_count, a, b, c, A, B, C){}
};

class Right : public Triangle {
public:
	Right(std::string name, int a, int b, int c, int A, int B) : Triangle(name, sides_count, a, b, c, A, B, 90){}
};

class Isosceles : public Triangle {
public:
	Isosceles(std::string name, int b, int A, int B) : Triangle(name, sides_count, 10, b, 10, A, B, 50) {}
};
class Equilateral : public Triangle {
public:
	Equilateral(std::string name) : Triangle(name, sides_count, 30, 30, 30, 60, 60, 60) {}
};

class Quadrangle : public Figure {
protected:
	Quadrangle(std::string name, int sides_count, int a, int b, int c, int d, int A, int B, int C, int D): Figure(name, 4, a, b, c, d, A, B, C, D) {}
public:
	Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(name, sides_count, a, b, c, d, A, B, C, D){}
};

class Rectangle : public Quadrangle {
public:
	Rectangle(std::string name, int a, int b) : Quadrangle(name, sides_count, a, b, a, b, 90, 90, 90, 90){}
};
class Square : public Rectangle {
public:
	Square(std::string name, int a) : Rectangle(name, a, a){}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(std::string name, int a, int b, int A, int B) : Quadrangle(name, sides_count, a, b, a, b, A, B, A, B) {
	}
};

class Romb : public Parallelogram {
public:
	Romb(std::string name,int a, int A, int B) : Parallelogram(name, a, a, A, B) {
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
	Figure* triangle = new Triangle("Труегольник", 10, 20, 30, 50, 60, 70);
	print_info(triangle, triangle->get_sides_count());
	Figure* right = new Right("Прямоугольный треугольник",10, 20, 30, 50, 60);
	print_info(right, right->get_sides_count());
	Figure* isosceles = new Isosceles("Равнобедренный треугольник", 30, 50, 60);
	print_info(isosceles, isosceles->get_sides_count());
	Figure* equilateral = new Equilateral("Равносторонний треугольник");
	print_info(equilateral, equilateral->get_sides_count());

	Figure* quadrangle = new Quadrangle("Четырехугольник", 10, 20, 30, 40, 50, 60, 70, 80);
	print_info(quadrangle, quadrangle->get_sides_count());
	Figure* rectangle = new Rectangle("Прямоугольник", 10, 20);
	print_info(rectangle, rectangle->get_sides_count());
	Figure* square = new Square("Квадрат", 20);
	print_info(square, square->get_sides_count());
	Figure* parallelogramm = new Parallelogram("Параллелограмм", 20, 30, 30, 40);
	print_info(parallelogramm, parallelogramm->get_sides_count());
	Figure* romb = new Romb("Ромб", 30, 30, 40);
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