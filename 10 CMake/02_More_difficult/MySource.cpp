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

	Triangle triangle(3, "Треугольник: \n");
	triangle.set_lenght_and_corners(10, 20, 30, 50, 60, 70);
	triangle.print_info();

	rightTriangle rightTriangle(3, "Прямоугольный треугольник:\n");
	rightTriangle.set_lenght_and_corners(10, 20, 30, 50, 60, 90);
	rightTriangle.print_info();

	isoscelesTriangle isoscelesTriangle(3, "Равнобедренный треугольник: \n");
	isoscelesTriangle.set_lenght_and_corners(10, 20, 10, 50, 60, 50);
	isoscelesTriangle.print_info();

	equilateraltriangle equilateraltriangle(3, "Равносторонний треугольник: \n");
	equilateraltriangle.set_lenght_and_corners(30, 30, 30, 60, 60, 60);
	equilateraltriangle.print_info();

	Quadrangle quadrangle(4, "Четырехугольник: \n");
	quadrangle.set_lenght_and_corners(10, 20, 30, 40, 50, 60, 70, 80);
	quadrangle.print_info();

	Rectangle rectangle(4, "Прямоугольник: \n");
	rectangle.set_lenght_and_corners(10, 20, 10, 20, 90, 90, 90, 90);
	rectangle.print_info();

	Square square(4, "Квадрат: \n");
	square.set_lenght_and_corners(20, 20, 20, 20, 90, 90, 90, 90);
	square.print_info();

	Parallelogram parallelogram(4, "Параллелограм: \n");
	parallelogram.set_lenght_and_corners(20, 30, 20, 30, 30, 40, 30, 40);
	parallelogram.print_info();

	Rhombus rhombus(4, "Ромб: \n");
	rhombus.set_lenght_and_corners(30, 30, 30, 30, 30, 40, 30, 40);
	rhombus.print_info();




}

