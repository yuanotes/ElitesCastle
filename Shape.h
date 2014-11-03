class Rectangle
{
public:
    Rectangle();
    Rectangle(float x, float y, float width, float height);
    Rectangle(const Rectangle& other);

    float getArea();

    float x; // x-axis of the Left of the rectangle
    float y; // y-axis of the top of the rectangle
    float width; // width of the rectangle
    float height; // height of the rectangle
};

class Circle
{
public:
    Circle();
    Circle(float x, float y, float radius);
    Circle(const Circle& other);

    float getArea();

    float x; // x-axis of the center of the circle
    float y; // x-axis of the center of the circle
    float radius; // radius of the center of the circle
};
