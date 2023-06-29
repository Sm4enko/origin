#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API 
#else
#define MATHPOWERLIBRARY_API 
#endif
#include <iostream>
#include <string>

class Figure {
protected:
	int sides_count;
	std::string name;
public:
	Figure(int num, std::string n);

	MATHPOWERLIBRARY_API int get_sides_count();
	MATHPOWERLIBRARY_API std::string what();
	MATHPOWERLIBRARY_API void print_info();
};








