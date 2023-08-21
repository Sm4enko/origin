#include <iostream>
#include <stdexcept>
#include "List.h"

int main() {
    List myList;

    myList.PushBack(1);
    myList.PushFront(2);
    myList.PushBack(3);
    myList.PushFront(4);

    std::cout << "List size: " << myList.Size() << std::endl;

    while (!myList.Empty()) {
        std::cout << "PopBack: " << myList.PopBack() << std::endl;
    }

    std::cout << "List size after popping all elements: " << myList.Size() << std::endl;

    return 0;
}

