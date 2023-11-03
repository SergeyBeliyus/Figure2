#include <iostream>
#include <windows.h>
#include <string>


class Figure {
protected:
	std::string name = "Фигура";
	int a, b, c, d, A, B, C, D;
public:
	Figure() {
		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->d = 0;
		this->A = 0;
		this->B = 0;
		this->C = 0;
		this->D = 0;
	}

	std::string get_name(){
		return name;
	}
	virtual std::string get_sides() {
		return ("Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d));
	}
	virtual std::string get_angles() {
		return ("Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D));
	}
};

class Triangle : public Figure{
public:
	Triangle(int a, int b, int c, int A, int B, int C) : Figure() {
		this->name = "Треугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	std::string get_sides() override {
		return ("Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c));
	}
	std::string get_angles() override {
		return ("Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C));
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure() {
		this->name = "Четырехугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}

	std::string get_sides() override {
		return ("Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d));
	}
	std::string get_angles() override {
		return ("Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D));
	}
};

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		this->name = "Прямоугольный треугольник";
	};
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int c, int A, int B) : Triangle(a, a, c, A, A, B) {
		this->name = "Равнобедренный треугольник";
	};
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
		this->name = "Равносторонний треугольник";
	};
};

class FRectangle : public Quadrangle {
public:
	FRectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
		this->name = "Прямоугольник";
	};
};


class Square : public FRectangle {
public:
	Square(int a) : FRectangle(a,a) {
		this->name = "Квадрат";
	};
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
		this->name = "Параллелограмм";
	};
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {
		this->name = "Ромб";
	};
};

void print_info(Figure* fig) {
	std::cout << fig->get_name() << std::endl;
	std::cout << fig->get_sides() << std::endl;
	std::cout << fig->get_angles() << "\n" << std::endl;
}


int main() {
	Triangle fig1 (10,20,30,50,60,70);
	RightTriangle fig2 (10, 20, 30, 50, 60);
	IsoscelesTriangle fig3 (10, 20, 50, 60);
	EquilateralTriangle fig4 (30);
	Quadrangle fig5(10,20,30,40,50,60,70,80);
	FRectangle fig6(10,20);
	Square fig7(10);
	Parallelogram fig8(10, 20, 30, 40);
	Rhombus fig9(30, 30, 40);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	print_info(&fig1);
	print_info(&fig2);
	print_info(&fig3);
	print_info(&fig4);
	print_info(&fig5);
	print_info(&fig6);
	print_info(&fig7);
	print_info(&fig8);
	print_info(&fig9);
}