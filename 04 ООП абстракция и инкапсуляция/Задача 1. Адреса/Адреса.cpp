




#include <iostream>
#include <string>
#include <fstream>

class adresses
{
public:
    std::string city, street;
    int house, apartment;
};



int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream fin("in.txt");
    std::string temp;
    int temp2;
    int N;
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

    fout << N << std::endl;
    for (int i = N - 1; i > -1; --i) {
        fout << objects[i].city << ", " << objects[i].street << ", " << objects[i].house << ", " << objects[i].apartment << std::endl;
    }

    fout.close();

    delete[] objects;
    return 0;
}
