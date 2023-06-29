#include <string>

class WordStorage {
public:
    static void setWord(const std::string& word);
    static void printWord();

private:
    static std::string storedWord;
};


