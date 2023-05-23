#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"

class adresses
{
public:
    std::string city, street;
    int house, apartment;
};



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream fin("in.txt");
    std::string temp;
    int temp2, N, less;
    int count = 0;
    fin >> N;
    int* sort = new int[N];
    adresses* objects = new adresses[N];

    for (int i = 0; i < N; ++i) {
        fin >> temp;
        objects[i].city = temp;
        fin >> temp;
        objects[i].street = temp;
        fin >> temp2;
        objects[i].house = temp2;
        fin >> temp2;
        objects[i].apartment = temp2;
    }

    fin.close();

    std::ofstream fout("out.txt");

    fout << N << std::endl;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (objects[i].city.size() < objects[j].city.size()) {
                less = objects[i].city.size();
            }
            else {
                less = objects[j].city.size();
            }
            if (objects[i].city[count] < objects[j].city[count]) {
                std::swap(objects[i], objects[j]);
            }
            else if (objects[i].city[i] == objects[j].city[j]) {
                while (count < less) {
                    if (objects[i].city[count] < objects[j].city[count]) {
                        std::swap(objects[i], objects[j]);
                        break;
                    }
                    ++count;
                }
                count = 0;
            }
            
        }
    }

        for (int i = 0; i < N; ++i) {
            fout << objects[i].city << ", " << objects[i].street << ", " << objects[i].house << ", " << objects[i].apartment << std::endl;
        }
        
        fout.close();
    

    delete[] objects;
    return 0;
}
