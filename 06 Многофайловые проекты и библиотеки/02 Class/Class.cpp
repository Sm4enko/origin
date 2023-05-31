#include "windows.h"

class Counter {
private:
    int num;

public:
    Counter(int n) {
        num = n;
    }
    int add() {
        num += 1;
        return num;
    }
    int subtract() {
        num -= 1;
        return num;
    }
    int getValue() {
        return num;
    }
};