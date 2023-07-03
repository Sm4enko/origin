#pragma once
#ifdef DYNAMICLIBRARY_EXPORTS // Препроцессор” - “Определения препроцессора
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif
#include <string>

class WordStorage {
public:
	MATHPOWERLIBRARY_API static void setWord(const std::string& word);
	MATHPOWERLIBRARY_API static void printWord();

private:
    static std::string storedWord;
};





