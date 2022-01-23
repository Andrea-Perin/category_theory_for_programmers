#include <cmath>
#include <iostream>

constexpr double pi() { return std::atan(1)*4; }

class Shape {
    public:
        virtual double area() = 0;
        virtual double circ() = 0;
};

class Rect : public Shape {
    public:
        Rect(double w, double h) : w(w), h(h) {}
        double area() { return w * h; }
        double circ() { return (w + h) * 2; }
    private:
        double h;
        double w;
};

class Circle : public Shape {
    public:
        Circle(double r) : r(r) {}
        double area() { return pi() * r * r; }
        double circ() { return pi() * 2 * r; }
    private:
        double r;
};

int main()
{
    Circle circ(2.);
    Rect rect(2., 1.);

    std::cout << circ.area() << "\n";
    std::cout << rect.area() << "\n";

}
