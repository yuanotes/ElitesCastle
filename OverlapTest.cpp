#include "Shape.h"
#include <cmath>

float square(float x){
    return x * x;
}

float distanceSquare(float x1, float y1, float x2, float y2){
    return square(x2 - x1)  + square(y2 - y1);
}

float distance(float x1, float y1, float x2, float y2){
    return sqrtf(distanceSquare(x1, y1, x2, y2));
}

// a * b = |a||b|cos(angle), a and b are vectors
float dotProduct(float x1, float y1, float x2, float y2){
    return x1 * x2  + y1 * y2;
}

float lineToPointDistance(float x1, float y1, float x2, float y2, float px, float py){
    // dotProduct get |a||b|cos(angle)
    // t = |a||b|cos(angle) / |a||a| ----> (|b|cos(angle))/(|a|)
    float t = dotProduct((px-x1), (py-y1), (x2-x1), (y2-y1)) / distanceSquare(x1, y1, x2, y2);

    // line start to the point has angle with 180 degree with line start to line end.
    if (t < 0){
        return distance(x1, y1, px, py);
    }

    // line start to the point has angle with 0 degree with line start to line end.
    if (t > 1){
        return distance(x2, y2, px, py);
    }

    // line start to the point has angle with degree from 0 to 180 with line start to line end.
    return distance(px, py, (x2 - x1) *t, (y2 - y1) * t);
}

bool lineIntersectCircle(float x1, float y1, float x2, float y2, const Circle* circle){
    return lineToPointDistance(x1, y1, x2, y2, circle->x, circle->y) <= circle->radius;
}


bool pointInRectangle(float x, float y, const Rectangle* rectangle){
    return (x >= rectangle->x &&
            y >= rectangle->y &&
            x <= (rectangle->x + rectangle->width) &&
            y <= (rectangle->y + rectangle->height));
}

bool isOverlapped(const Rectangle* r, const Circle* c){
    // Circle center in rectangle
    return pointInRectangle(c->x, c->y, r) ||
            // bottom line intersect with c
                    lineIntersectCircle(r->x, r->y, r->x + r->width, r->y, c) ||
            // left line intersect with c
                    lineIntersectCircle(r->x, r->y, r->x, r->y + r->height, c) ||
            // top line intersect with c
                    lineIntersectCircle(r->x, r->y + r->height, r->x + r->width, r->y + r->height, c) ||
            // right line intersect with c
                    lineIntersectCircle(r->x + r->width, r->y, r->x + r->width, r->y + r->height, c);
}
