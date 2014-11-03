#include "Shape.h"
Rectangle::Rectangle() {
    this->x = 0;
    this->y = 0;
    this->height = 0;
    this->width = 0;
}

Rectangle::Rectangle(const Rectangle &other) {
    this->x = other.x;
    this->y = other.y;
    this->width = other.width;
    this->height = other.height;
}

Rectangle::Rectangle(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

float Rectangle::getArea() {
    return this->width * this->height;
}

Circle::Circle() {
    this->x = 0;
    this->y = 0;
    this->radius = 0;
}

Circle::Circle(float x, float y, float radius) {
    this->x = x;
    this->y = y;
    this->radius =radius;
}

Circle::Circle(const Circle &other) {
    this->x = other.x;
    this->y = other.y;
    this->radius = other.radius;
}

float Circle::getArea() {
    return this->radius * this->radius * 3.14159265f;
}



