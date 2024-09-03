#include <iostream>

class Figure
{
public:
	Figure() {
		char z = 0;
	}
	virtual void print_info() {
		std::cout << "Figure: " << std::endl;
		std::cout << (check() ? "coreccted" : "wrong") << std::endl;
		std::cout << "Sides: 0" << std::endl;
		std::cout << std::endl;
	};
	virtual bool check() {
		return true;
	};
public:
	virtual void set_name(std::string name) {};
	~Figure() {};
};

class Triangle : public Figure
{
public:
	Triangle(int a, int b, int c, int A, int B, int C) : a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {};
	~Triangle() {};

	void set_name(std::string name) override {
		this->name = name;
	}

	void print_info() override {
		std::cout << name << std::endl;
		std::cout << (check() ? "coreccted" : "wrong") << std::endl;
		std::cout << "Sides count: 3" << std::endl;
		std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << std::endl;
		std::cout << std::endl;

	}

	bool check() override {
		return(A + B + C == 180) && (a != 0 && b != 0 && c != 0);
	}
	
	
protected:
	int a, b, c, A, B, C;
	std::string name = "Triangle";
};

class Quadrangle : public Figure
{
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {};
	~Quadrangle() {};

	void set_name(std::string name) override {
		this->name = name;
	}

	void print_info() override {
		std::cout << name << std::endl;
		std::cout << (check() ? "corrected":"wrong") << std::endl;
		std::cout << "Sides count: 4" << std::endl;
		std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << "d=" << d << std::endl;
		std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << "D=" << D << std::endl;
		std::cout << std::endl;
	}

	bool check() override {
		return (A + B + C + D == 360) && (a != 0 && b != 0 && c != 0 && d != 0);
	}
protected:
	int a, b, c, d, A, B, C, D;
	std::string name = "Quadrangle";
};



class RightTriangle : public Triangle
{
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		Triangle::set_name(name);
	};

	bool check() override {
		return Triangle::check() && (C == 90);
	};
	~RightTriangle() {};

private:
	std::string name = "Right triangle";
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B ) : Triangle(a, b, a, A, B, A) {
		Triangle::set_name(name);
	};
	bool check() override {
		return Triangle::check() && (a != b && A != B);
	};
	~IsoscelesTriangle() {};

private:
	std::string name = "Isosceless Triangle";
};

class EquilateralTriangle : public Triangle {
public: 
	EquilateralTriangle(int a) :Triangle(a, a, a, 60, 60, 60) {
		Triangle::set_name(name);
	};
	bool check() override {
		return Triangle::check();
	}
	~EquilateralTriangle() {};
private: 
	std::string name = "Equilateral triangle";
};

class Rectangle : public Quadrangle
{
public:
	Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
		Quadrangle::set_name(name);
	};
	bool check() override {
		return Quadrangle::check() && (a != b);
	}

	~Rectangle() {};

private:
	std::string name = "Rectangle";
};

class Square : public Quadrangle
{
public:
	Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
		Quadrangle::set_name(name);
	};
	~Square() {};
	bool check() override {
		return Quadrangle::check();
	}
private:
	std::string name = "Square";
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
		Quadrangle::set_name(name);
	};

	bool check() override {
		return Quadrangle::check() && ((a != b) && (A != B));
	}
	~Parallelogram() {};
private:
	std::string name = "Parallelogram";
};

class Rhombus : public Quadrangle
{
public:
	Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B) {
		Quadrangle::set_name(name);
	};

	bool check() override {
		return Quadrangle::check() && (A != B);
	}
	~Rhombus() {};
private:
	std::string name = "Rhombus ";
};


int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	Figure figure;
	figure.print_info();

	RightTriangle rightTriangle(10, 20, 30, 50, 40);
	IsoscelesTriangle isoscelesTriangle(50, 40, 50, 80);
	Triangle triangle(3, 3, 3, 90, 60, 40);
	Square square(20);
	Rhombus rhombus(30, 60, 120);


	Figure* figure_poly;
	figure_poly = &rightTriangle;
	figure_poly->print_info();

	figure_poly = &isoscelesTriangle;
	figure_poly->print_info();

	figure_poly = &triangle;
	figure_poly->print_info();

	figure_poly = &square;
	figure_poly->print_info();

	figure_poly = &rhombus;
	figure_poly->print_info();

	return 0;
}

