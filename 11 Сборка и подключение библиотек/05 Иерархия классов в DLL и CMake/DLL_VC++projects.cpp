#include <iostream>
#include <string>
#include "../05 �������� ������� � DLL � CMake/Triangle.h"
#include "../05 �������� ������� � DLL � CMake/Figure.h"
#include "../05 �������� ������� � DLL � CMake/isoscelesTriangle.h"
#include "../05 �������� ������� � DLL � CMake/Quadrangle.h"
#include "../05 �������� ������� � DLL � CMake/rightTriangle.h"
#include "../05 �������� ������� � DLL � CMake/Parallelogram.h"
#include "../05 �������� ������� � DLL � CMake/equilateraltriangle.h"
#include "../05 �������� ������� � DLL � CMake/Rectangle.h"
#include "../05 �������� ������� � DLL � CMake/Rhombus.h"
#include "../05 �������� ������� � DLL � CMake/Square.h"



int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle triangle(3, "�����������: \n");
	triangle.set_lenght_and_corners(10, 20, 30, 50, 60, 70);
	triangle.print_info();

	rightTriangle rightTriangle(3, "������������� �����������:\n");
	rightTriangle.set_lenght_and_corners(10, 20, 30, 50, 60, 90);
	rightTriangle.print_info();

	isoscelesTriangle isoscelesTriangle(3, "�������������� �����������: \n");
	isoscelesTriangle.set_lenght_and_corners(10, 20, 10, 50, 60, 50);
	isoscelesTriangle.print_info();

	equilateraltriangle equilateraltriangle(3, "�������������� �����������: \n");
	equilateraltriangle.set_lenght_and_corners(30, 30, 30, 60, 60, 60);
	equilateraltriangle.print_info();

	Quadrangle quadrangle(4, "���������������: \n");
	quadrangle.set_lenght_and_corners(10, 20, 30, 40, 50, 60, 70, 80);
	quadrangle.print_info();

	Rectangle rectangle(4, "�������������: \n");
	rectangle.set_lenght_and_corners(10, 20, 10, 20, 90, 90, 90, 90);
	rectangle.print_info();

	Square square(4, "�������: \n");
	square.set_lenght_and_corners(20, 20, 20, 20, 90, 90, 90, 90);
	square.print_info();

	Parallelogram parallelogram(4, "�������������: \n");
	parallelogram.set_lenght_and_corners(20, 30, 20, 30, 30, 40, 30, 40);
	parallelogram.print_info();

	Rhombus rhombus(4, "����: \n");
	rhombus.set_lenght_and_corners(30, 30, 30, 30, 30, 40, 30, 40);
	rhombus.print_info();




}

