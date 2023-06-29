#pragma once
#ifdef MATHPOWERLIBRARYDYNAMIC_EXPORTS
#define MATHPOWERLIBRARY_API 
#else
#define MATHPOWERLIBRARY_API 
#endif
#include <string>

class WordStorage {
public:
	MATHPOWERLIBRARY_API static void setWord(const std::string& word);
	MATHPOWERLIBRARY_API static void printWord();

private:
    static std::string storedWord;
};





