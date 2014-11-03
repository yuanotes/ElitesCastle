#include <iostream>
#include <vector>

#include "Shape.h"

using namespace std;

void test_shape(){

    Rectangle r1 = Rectangle::Rectangle();
    cout << (r1.x == 0) << (r1.y == 0) << (r1.width ==0) << (r1.height == 0) << endl;
    cout << (r1.getArea() == 0) << endl;

    Rectangle *r2 = new Rectangle(0, 0, 100, 200);
    cout << (r2->x == 0) << (r2->y == 0) << (r2->width == 100) << (r2->height == 200) << endl;
    cout << (r2->getArea() == 100 * 200) << endl;

    Rectangle r3 = Rectangle::Rectangle(*r2);
    cout << (r3.x == 0) << (r3.y == 0) << (r3.width == r2->width ) << (r3.height == r2->height) << endl;
    cout << (r3.getArea() == r2->getArea()) << endl;

    delete r2; r2 = 0;

    Circle c1 = Circle::Circle();
    cout << (c1.x == 0) << (c1.y == 0) << (c1.radius ==0) << endl;
    cout << (c1.getArea() == 0) << endl;

    Circle *c2 = new Circle(0, 0, 100);
    cout << (c2->x == 0) << (c2->y == 0) << (c2->radius == 100) << endl;
    cout << (c2->getArea() == 100 * 100 * 3.14159265f) << endl;

    Circle c3 = Circle::Circle(*c2);
    cout << (c3.x == 0) << (c3.y == 0) << (c3.radius == c2->radius) << endl;
    cout << (c3.getArea() == c2->getArea()) << endl;

    delete  c2; c2 = 0;
}

extern bool isOverlapped(const Rectangle* r, const Circle* c);

void test_overlap(){
    Rectangle r = Rectangle::Rectangle(0, 0, 100, 100);

    Circle c0 = Circle::Circle(50, 50, 100);   // circle in rectangle
    Circle c1 = Circle::Circle(160, 180, 100); // circle at right top corner of rectangle
    Circle c11 = Circle::Circle(161, 181, 100);   // circle at right top corner and not in rectangle

    Circle c2 = Circle::Circle(160, -80, 100); // circle at right bottom corner of rectangle
    Circle c22 = Circle::Circle(161, -81, 100); // circle at  right bottom corner and not in rectangle

    Circle c3 = Circle::Circle(-60, -80, 100); // circle at left bottom corner of rectangle
    Circle c33 = Circle::Circle(-61, -81, 100); // circle at left bottom corner and not in rectangle

    Circle c4 = Circle::Circle(-60, 180, 100); // circle at left bottom corner of rectangle
    Circle c44 = Circle::Circle(-61, 181, 100); // circle at left bottom corner and not in rectangle

    cout << isOverlapped(&r, &c0) << endl;
    cout << isOverlapped(&r, &c1) << endl;
    cout << !isOverlapped(&r, &c11) << endl;
    cout << isOverlapped(&r, &c2) << endl;
    cout << !isOverlapped(&r, &c22) << endl;
    cout << isOverlapped(&r, &c3) << endl;
    cout << !isOverlapped(&r, &c33) << endl;
    cout << isOverlapped(&r, &c4) << endl;
    cout << !isOverlapped(&r, &c44) << endl;
}


typedef pair<double, double> Stop;
typedef vector<Stop> Path;

extern int get_stop(Path path);

void test_path(){
    // Test no stop
    Path path1;
    cout << (get_stop(path1) == -1) << endl;

    // Test one stop and get through
    Path path2 {Stop{10, 10}};
    cout << (get_stop(path2) == 0) << endl;

    // Test one stop and failed
    Path path3 {Stop{10, 20}};
    cout << (get_stop(path3) == -1) << endl;

    // Test two stop and get through
    Path path4 {Stop{10, 10}, Stop{10,10}};
    cout << (get_stop(path4) == 0) << endl;

    // Test two stop and get through
    Path path5 {Stop{10, 20}, Stop{20,10}};
    cout << (get_stop(path5) == 1)<< endl;

    // Test some stops and get through
    Path path6 {Stop{10, 20}, Stop{20,10}, Stop{10,10}, Stop{10, 10}};
    cout << (get_stop(path6) == 1)<< endl;

}

int main() {
    cout << "Test Shape." << endl;
    test_shape();
    cout << "Test Shape finished." << endl;

    cout << "Test Overlap." << endl;
    test_overlap();
    cout << "Test Overlap finished." << endl;

    cout << "Test Stops." << endl;
    test_path();
    cout << "Test Stops finished." << endl;
    return 0;
}

