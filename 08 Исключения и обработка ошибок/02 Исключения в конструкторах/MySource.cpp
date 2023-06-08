#include "Check.h"
#include <iostream>
#include <string>
#include "figure.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "rightTriangle.h"
#include "isoscelesTriangle.h"
#include "equilateraltriangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	int sides, a, b, c, d, e, f, g, h;
	try {
		sides = 3;
		if (sides != 3) {
			throw "Ошибка создания фигуры. Причина: количество сторон";
		}
		Triangle triangle(3, "Треугольник:\n");
		d = 50;
		e = 60;
		f = 70;
		if (d + e + f != 180) {
			throw "Ошибка создания фигуры. Причина: сумма углов не равна 180";
		}
		triangle.set_lenght_and_corners(10, 20, 30, d, e, f);
		triangle.print_info();

		rightTriangle rightTriangle(3, "Прямоугольный треугольник:\n");
		f = 90;
		if (f != 90) {
			throw "Ошибка создания фигуры. Причина: угол C не равен 90";
		}
		rightTriangle.set_lenght_and_corners(10, 20, 30, 50, 60, f);
		rightTriangle.print_info();
		a = 10;
		c = 10;
		if (a != c) {
			throw "Ошибка создания фигуры. Причина: сторона A не равна стороне C";
		}
		isoscelesTriangle isoscelesTriangle(3, "Равнобедренный треугольник: \n");
		d = 50;
		f = 50;
		if (d != f) {
			throw "Ошибка создания фигуры. Причина: угол А не равен углу C";
		}
		isoscelesTriangle.set_lenght_and_corners(a, 20, c, d, 60, f);
		isoscelesTriangle.print_info();
		a = 30;
		b = 30;
		c = 30;
		if (a != b && a != c) {
			throw "Ошибка создания фигуры. Причина: стороны не равны";
		}
		equilateraltriangle equilateraltriangle(3, "Равносторонний треугольник: \n");
		d = 60;
		e = 60;
		f = 60;
		if (d != e && d != f) {
			throw "Ошибка создания фигуры. Причина: углы не равны";
		}
		equilateraltriangle.set_lenght_and_corners(a, b, c, d, e, f);
		equilateraltriangle.print_info();

		sides = 4;
		if (sides != 4) {
			throw "Ошибка создания фигуры. Причина: количество сторон";
		}
		Quadrangle quadrangle(4, "Четырехугольник: \n");
		e = 50;
		f = 60;
		g = 70;
		h = 80;
		if (50 + 60 + 70 + 80 != 360) {
			throw "Ошибка создания фигуры. Причина: сумма углов не равна 360 градусов";
		}
		quadrangle.set_lenght_and_corners(10, 20, 30, 40, e, f, g, h);
		quadrangle.print_info();

		a = 10;
		b = 20;
		c = 10;
		d = 20;
		if (a != c && b != d) {
			throw "Ошибка создания фигуры. Причина: стороны попарно не равны";
		}
		Rectangle rectangle(4, "Прямоугольник: \n");
		e = 50;
		f = 60;
		g = 70;
		h = 80;
		if (e != 90 && f != 90 && g != 90 && h != 90) {
			throw "Ошибка создания фигуры. Причина: углы не равны 90";
		}
		rectangle.set_lenght_and_corners(a, b, c, d, e, f, g, h);
		rectangle.print_info();

		a = 20;
		b = 20;
		c = 20;
		d = 20;
		if (a != b && a != c && a != d) {
			throw "Ошибка создания фигуры. Причина: стороны не равны";
		}
		Square square(4, "Квадрат: \n");
		e = 90;
		f = 90;
		g = 90;
		h = 90;
		if (e != 90 && f != 90 && g != 90 && h != 90) {
			throw "Ошибка создания фигуры. Причина: углы не равны 90";
		}
		square.set_lenght_and_corners(a, b, c, d, e, f, g, h);
		square.print_info();

		a = 20;
		b = 20;
		c = 20;
		d = 20;
		if (a != b && a != c && a != d) {
			throw "Ошибка создания фигуры. Причина: стороны попарно не равны";
		}
		Parallelogram parallelogram(4, "Параллелограм: \n");
		e = 90;
		f = 90;
		g = 90;
		h = 90;
		if (e != g && f != h) {
			throw "Ошибка создания фигуры. Причина: углы попарно не равны";
		}
		parallelogram.set_lenght_and_corners(a, b, c, d, 30, 40, 30, 40);
		parallelogram.print_info();

		a = 30;
		b = 30;
		c = 30;
		d = 30;
		if (a != b && a != c && a != d) {
			throw "Ошибка создания фигуры. Причина: стороны не равны";
		}

		Rhombus rhombus(4, "Ромб: \n");
		e = 30;
		f = 40;
		g = 30;
		h = 40;
		if (30 != 30 && 40 != 40) {
			throw "Ошибка создания фигуры. Причина: углы попарно не равны";
		}
		rhombus.set_lenght_and_corners(a, b, c, d, e, f, g, h);
		rhombus.print_info();
	}
	catch (const char* exception) {
		std::cout << exception << std::endl;
	}
}
