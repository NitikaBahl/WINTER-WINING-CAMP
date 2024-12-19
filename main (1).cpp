#include <iostream>
using namespace std;

class Calculate {
public:
    
    double area(double radius) {
        return 3.14 * radius * radius;
    }
    
    double area(double length, double breadth) {
        return length * breadth;
    }

    double area(double base, double height, bool isTriangle) {
        return 0.5 * base * height;
    }
};

int main() {
    Calculate calc;

    cout << "Area of Circle: " << calc.area(5.0) << endl;                  
    cout << "Area of Rectangle: " << calc.area(10.0, 20.0) << endl;       
    cout << "Area of Triangle: " << calc.area(5.0, 10.0, true) << endl;    

    return 0;
}