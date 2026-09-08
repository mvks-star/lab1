#pragma once
ref class lab1_classes
{
	double a, b;
public:
	ZavdClass() { a = 1; b = 1; } // Параметризований конструктор
	void Fn_b(double x, double y, double z); // Обчислення функції b[x,y,z]
	void Fn_a(double x, double y, double z); // Обчислення функції a[x,y,z,b]
	double Faktr(int n); // Обчислення факторіалу
	double geta() { return a; }
	double getb() { return b; }
};

