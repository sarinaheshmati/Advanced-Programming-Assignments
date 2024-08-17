#include "Vector2D.h"
#include <iostream>
using namespace std;
 
int main() {

    Vector2D v1(1, 2), v2;

    cout << "v1 = " << v1 << endl;
    cin >> v2; // INPUT: (2,1)
    Vector2D Sum = v1 + v2;
    Vector2D Subtract = v1 - v2;
    int innerProduct = v1 * v2;
    cout << "Sum = " << Sum << endl;  //OUTPUT: Sum= (3,3)
    cout << "Subtract = " << Subtract << endl;   //OUTPUT: Subtract: (-1,1)
    cout << "Inner Product = " << innerProduct << endl;  //OUTPUT:Inner Product= 4
    
}
