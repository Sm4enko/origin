#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"


class adresses {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    adresses(const std::string& city, const std::string& street, int house, int apartment)
        : city(city), street(street), house(house), apartment(apartment) {}

    std::string getCity() const {
        return city;
    }

    std::string getStreet() const {
        return street;
    }

    int getHouse() const {
        return house;
    }

    int getApartment() const {
        return apartment;
    }
};

void sort(adresses* objects, int N) {
    int less;

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
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream fin("in.txt");
    std::string temp;
    int temp2, N;
    int count = 0;
    fin >> N;
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

    sort(objects, N);

    fout << N << std::endl;

    for (int i = 0; i < N; ++i) {
        fout << objects[i].city << ", " << objects[i].street << ", " << objects[i].house << ", " << objects[i].apartment << std::endl;
    }

    fout.close();


    delete[] objects;
    return 0;
}
