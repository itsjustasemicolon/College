#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;
class Shape {
public:
    virtual ~Shape() = default;
    virtual void print()= 0;
};


class TwoDShape : public Shape {
public:
    virtual double getArea() = 0;
};


class ThreeDShape : public Shape {
public:
    virtual double surArea()=0;
    virtual double getVolume() = 0;
};


class Circle : public TwoDShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea()   {
        return 3.14 * radius * radius;
    }
    void print()   {
        cout << "Circle: Area = " << getArea() << endl;
    }
};


class Rectangle : public TwoDShape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea()   {
        return width * height;
    }
    void print()   {
        cout << "Rectangle: Area = " << getArea() << endl;
    }
};


class Sphere : public ThreeDShape {
private:
    double radius;
public:
    Sphere(double r) : radius(r) {}
    double surArea()   {
        return 4 * 3.14 * radius * radius;
    }
    double getVolume()   {
        return (4.0 / 3) * 3.14 * radius * radius * radius;
    }
    void print()   {
        cout << "Sphere: Area = " << surArea() << ", Volume = " << getVolume() << endl;
    }
};


class Cube : public ThreeDShape {
private:
    double side;
public:
    Cube(double s) : side(s) {}
    double surArea()   {
        return 6 * side * side;
    }
    double getVolume()   {
        return side * side * side;
    }
    void print()   {
        cout << "Cube: Area = " << surArea() << ", Volume = " << getVolume() << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    
    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(make_unique<Sphere>(3.0));
    shapes.push_back(make_unique<Cube>(2.0));

    
    for ( auto& shape : shapes) {
        shape->print();
    }

    return 0;
}
