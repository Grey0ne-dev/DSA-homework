#include <iostream>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

class Person {
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(std::move(n)), age(a) {
        cout << "Person constructor called: " << endl;
    }
};

class Point {
    double x, y;
public:
    Point(double x, double y) : x(x), y(y) {
        cout << "Point constructor called: " << x << ", " << y << endl;
    }
};

template <typename T, typename... Args>
auto makeObject(Args&&... args) {
    return new T(std::forward<Args>(args)...);
}


int main() {
    Person* p1 = makeObject<Person>("Alice", 25);
    Point* pt1 = makeObject<Point>(3.5, 4.2);
    

    delete p1;
    delete pt1;
    
    return 0;
}