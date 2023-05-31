#pragma once
#include <iostream>
#include <string>

class Figure {
protected:
	int sides_count;
	std::string name;
public:
	Figure(int num, std::string n);

	int get_sides_count();
	std::string what();
	void print_info();
};


