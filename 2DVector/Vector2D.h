//
//  Vector2D.h
//  main6
//
//  Created by MacBook on 1/31/1401 AP.
//

#ifndef Vector2D_h
#define Vector2D_h
#include <iostream>

class Vector2D
{
    friend std::ostream &operator<<(std::ostream&, const Vector2D&);
    friend std::istream &operator>>(std::istream&, Vector2D&);
public:
    explicit Vector2D (int = 0, int = 0);
    
    void setX(int);
    int getX() const;
    void setY(int);
    int getY() const;
    
    Vector2D operator+(Vector2D);
    Vector2D operator-(Vector2D);
    int operator*(Vector2D);

private:
    int x;
    int y;
};


#endif /* Vector2D_h */
