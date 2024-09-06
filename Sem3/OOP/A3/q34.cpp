#include <bits/stdc++.h>
using namespace std;


class Shape {
public:

    virtual string getName() const = 0;
    virtual double getArea() const = 0;


    virtual ~Shape() {}
};


class TwoDShape : public Shape {
public:

    virtual ~TwoDShape() {}
};


class ThreeDShape : public Shape {
public:

    virtual double getVolume() const = 0;
    virtual ~ThreeDShape() {}
};


class Circle : public TwoDShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    string getName() const override {
        return "Circle";
    }

    double getArea() const override {
        return M_PI * radius * radius;
    }
};


class Triangle : public TwoDShape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    string getName() const override {
        return "Triangle";
    }

    double getArea() const override {
        return 0.5 * base * height;
    }
};

class Ellipse : public TwoDShape {
private:
    double majorAxis, minorAxis;

public:
    Ellipse(double a, double b) : majorAxis(a), minorAxis(b) {}

    string getName() const override {
        return "Ellipse";
    }

    double getArea() const override {
        return M_PI * majorAxis * minorAxis;
    }
};


class Sphere : public ThreeDShape {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    string getName() const override {
        return "Sphere";
    }

    double getArea() const override {
        return 4 * M_PI * radius * radius;
    }
    
    double getVolume() const override {
        return (4.0 / 3) * M_PI * pow(radius, 3);
    }
};

class Cube : public ThreeDShape {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    string getName() const override {
        return "Cube";
    }

    double getArea() const override {
        return 6 * side * side;
    }

    double getVolume() const override {
        return pow(side, 3);
    }
};

int main() {

    vector<Shape*> shapes;

    shapes.push_back(new Circle(3.0));
    shapes.push_back(new Triangle(3.0, 4.0));
    shapes.push_back(new Ellipse(5.0, 2.0));
    shapes.push_back(new Sphere(4.0));
    shapes.push_back(new Cube(2.0));

    for (Shape* shape : shapes) {
        cout << "Shape: " << shape->getName() << endl;
        cout << "Area: " << shape->getArea() << endl;


        ThreeDShape* threeDShape = dynamic_cast<ThreeDShape*>(shape);
        if (threeDShape) {
            cout << "Volume: " << threeDShape->getVolume() << endl;
        }

        cout << "--------------------------" << endl;
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
