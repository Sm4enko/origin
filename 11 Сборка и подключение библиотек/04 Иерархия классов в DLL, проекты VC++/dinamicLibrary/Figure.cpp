#include "Figure.h"

Figure::Figure(int num, std::string n) : sides_count(num), name(n) {}

int Figure::get_sides_count() {
	return sides_count;
}

std::string Figure::what() {
	return name;
}

void Figure::print_info() {
	std::cout << what() << get_sides_count() << std::endl;
}
