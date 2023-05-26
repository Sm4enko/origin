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
    adresses() : city(""), street(""), house(0), apartment(0) {}
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

    void setCity(std::string city) {
        this->city = city;
    }

    void setStreet(std::string street) {
        this->street = street;
    }

    void setHouse(int house) {
        this->house = house;
    }

    void setApartment(int apartment) {
        this->apartment = apartment;
    }

};

void sort(adresses* objects, int N) {
    int less;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (objects[i].getCity().size() < objects[j].getCity().size()) {
                less = objects[i].getCity().size();
            }
            else {
                less = objects[j].getCity().size();
            }
            if (objects[i].getCity()[count] < objects[j].getCity()[count]) {
                std::swap(objects[i], objects[j]);
            }
            else if (objects[i].getCity()[i] == objects[j].getCity()[j]) {
                while (count < less) {
                    if (objects[i].getCity()[count] < objects[j].getCity()[count]) {
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
    fin >> N;
    adresses* objects = new adresses[N];

    for (int i = 0; i < N; ++i) {
        fin >> temp;
        objects[i].setCity(temp);
        fin >> temp;
        objects[i].setStreet(temp);
        fin >> temp2;
        objects[i].setHouse(temp2);
        fin >> temp2;
        objects[i].setApartment(temp2);
    }

    fin.close();

    std::ofstream fout("out.txt");

    sort(objects, N);

    fout << N << std::endl;

    for (int i = 0; i < N; ++i) {
        fout << objects[i].getCity() << ", " << objects[i].getStreet() << ", " << objects[i].getHouse() << ", " << objects[i].getApartment() << std::endl;
    }

    fout.close();


    delete[] objects;
    return 0;
}
