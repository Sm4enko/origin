#include <iostream>
#include <vector>

class Point {
public:
    double x, y, z;

    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    void display() const {
        std::cout << '(' << x << ", " << y << ", " << z << ')';
    }
};

class Subject {
public:
    virtual void scale(double factor) = 0;
    virtual void scale(double factorX, double factorY, double factorZ) = 0;
    virtual void transform(double dx, double dy, double dz) = 0;
    virtual void display() const = 0;
    virtual ~Subject() {}
};

class Line : public Subject {
private:
    Point startPoint, endPoint;

public:
    Line(const Point& startPoint, const Point& endPoint) : startPoint(startPoint), endPoint(endPoint) {}

    void scale(double factor) override {
        startPoint.x *= factor;
        startPoint.y *= factor;
        startPoint.z *= factor;
        endPoint.x *= factor;
        endPoint.y *= factor;
        endPoint.z *= factor;
    }

    void scale(double factorX, double factorY, double factorZ) override {
        startPoint.x *= factorX;
        startPoint.y *= factorY;
        startPoint.z *= factorZ;
        endPoint.x *= factorX;
        endPoint.y *= factorY;
        endPoint.z *= factorZ;
    }

    void transform(double dx, double dy, double dz) override {
        startPoint.x += dx;
        startPoint.y += dy;
        startPoint.z += dz;
        endPoint.x += dx;
        endPoint.y += dy;
        endPoint.z += dz;
    }

    void display() const override {
        std::cout << "Линия: Начальная точка ";
        startPoint.display();
        std::cout << ", Конечная точка ";
        endPoint.display();
        std::cout << std::endl;
    }
};

class Rectangle : public Subject {
private:
    Point topLeft;
    double width, height;

public:
    Rectangle(const Point& topLeft, double width, double height) : topLeft(topLeft), width(width), height(height) {}

    void scale(double factor) override {
        width *= factor;
        height *= factor;
    }

    void scale(double factorX, double factorY, double factorZ) override {
        std::cerr << "Невозможно применить масштабирование по осям к данному типу фигуры." << std::endl;
    }

    void transform(double dx, double dy, double dz) override {
        topLeft.x += dx;
        topLeft.y += dy;
        topLeft.z += dz;
    }

    void display() const override {
        std::cout << "Прямоугольник: Верх, слева ";
        topLeft.display();
        std::cout << ", Ширина " << width << ", Высота " << height << std::endl;
    }
};

class Parallipiped : public Subject {
private:
    Point corner1, corner2;

public:
    Parallipiped(const Point& corner1, const Point& corner2) : corner1(corner1), corner2(corner2) {}

    void scale(double factor) override {
        corner1.x *= factor;
        corner1.y *= factor;
        corner1.z *= factor;
        corner2.x *= factor;
        corner2.y *= factor;
        corner2.z *= factor;
    }

    void scale(double factorX, double factorY, double factorZ) override {
        corner1.x *= factorX;
        corner1.y *= factorY;
        corner1.z *= factorZ;
        corner2.x *= factorX;
        corner2.y *= factorY;
        corner2.z *= factorZ;
    }

    void transform(double dx, double dy, double dz) override {
        corner1.x += dx;
        corner1.y += dy;
        corner1.z += dz;
        corner2.x += dx;
        corner2.y += dy;
        corner2.z += dz;
    }

    void display() const override {
        std::cout << "Параллепипед: Угол1 ";
        corner1.display();
        std::cout << ", Угол2 ";
        corner2.display();
        std::cout << std::endl;
    }
};

class Circle : public Subject {
private:
    Point center;
    double radius;

public:
    Circle(const Point& center, double radius) : center(center), radius(radius) {}

    void scale(double factor) override {
        radius *= factor;
    }

    void scale(double factorX, double factorY, double factorZ) override {
        std::cerr << "Невозможно применить масштабирование по осям к данному типу фигуры." << std::endl;
    }

    void transform(double dx, double dy, double dz) override {
        center.x += dx;
        center.y += dy;
        center.z += dz;
    }

    void display() const override {
        std::cout << "Окружность: Центр ";
        center.display();
        std::cout << ", Радиус " << radius << std::endl;
    }
};

class Cylinder : public Subject {
private:
    Point baseCenter;
    double radius, height;

public:
    Cylinder(const Point& baseCenter, double radius, double height) : baseCenter(baseCenter), radius(radius), height(height) {}

    void scale(double factor) override {
        radius *= factor;
        height *= factor;
    }

    void scale(double factorX, double factorY, double factorZ) override {
        baseCenter.x *= factorX;
        baseCenter.y *= factorY;
        baseCenter.z *= factorZ;
        radius *= factorX;  
        height *= factorZ; 
    }

    void transform(double dx, double dy, double dz) override {
        baseCenter.x += dx;
        baseCenter.y += dy;
        baseCenter.z += dz;
    }

    void display() const override {
        std::cout << "Цилиндр: Центр ";
        baseCenter.display();
        std::cout << ", Радиус " << radius << ", Высота " << height << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Subject*> subjects;

    Line* line = new Line(Point(7, 7, 7), Point(9, 9, 9));
    Rectangle* rectangle = new Rectangle(Point(1, 1, 1), 3, 4);
    Parallipiped* parallipiped = new Parallipiped(Point(8, 8, 8), Point(10, 10, 10));
    Circle* circle = new Circle(Point(0, 0, 0), 4);
    Cylinder* cylinder = new Cylinder(Point(12, 12, 12), 4, 9);
    
   
    subjects.push_back(line);
    subjects.push_back(rectangle);
    subjects.push_back(parallipiped);
    subjects.push_back(circle);
    subjects.push_back(cylinder);
   
    

    std::cout << "До:" << std::endl;
    for (const auto& figure : subjects) {
        figure->display();
    }

    for (auto& shape : subjects) {
        shape->scale(1.5);
        shape->transform(2, 2, 2);
    }

    std::cout << "\nПосле:" << std::endl;
    for (const auto& figure : subjects) {
        figure->display();
    }

    for (const auto& figure : subjects) {
        delete figure;
    }

    return 0;
}
