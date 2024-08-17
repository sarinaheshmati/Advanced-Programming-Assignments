//
//  Vector2D.cpp
//  main6
//
//  Created by MacBook on 1/31/1401 AP.
//

#include "Vector2D.h"
#include <iomanip>

using namespace std;


Vector2D::Vector2D (int x, int y)
{
    setX(x);
    setY(y);
}

void Vector2D::setX(int xx)
{
    x = xx;
}

int Vector2D::getX() const
{
    return x;
}

void Vector2D::setY(int yy)
{
    y = yy;
}

int Vector2D::getY() const
{
    return y;
}

Vector2D Vector2D::operator+(Vector2D right)
{
    Vector2D c;
    c.setX(getX() + right.getX());
    c.setY(getY() + right.getY());
    return c;
}

Vector2D Vector2D::operator-(Vector2D right)
{
    Vector2D c;
    c.setX(getX() - right.getX());
    c.setY(getY() - right.getY());
    return c;
}

int Vector2D::operator*(Vector2D right)
{
    int b ,c;
    b = (getX() * right.getX());
    c = (getY() * right.getY());
    return b + c;
}

istream &operator>>(istream &input, Vector2D &vector)
{
    input.ignore();
    input >> setw(1) >> vector.x;
    input.ignore();
    input >> setw(1) >> vector.y;
    return input;
}

ostream &operator<<(ostream &output, const Vector2D &vector)
{
    output << "(" << vector.x << ", " << vector.y << ")";
    return output;
}
