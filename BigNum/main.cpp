//
//  main.cpp
//  project1
//
//  Created by MacBook on 2/15/1401 AP.
//

#include <iostream>
#include "Bignum.h"

using namespace std;

int main()
{
    Bignum a("-2222222222222222222");
    Bignum b("-11111111111111111");
    
    if (a > b)
    {
        cout << a << ">" << b << endl;
    }
    
//    cout << "a + b = " << a + b << endl;
//    cout << "a - b = " << a - b << endl;
//    cout << "a * b = " << a * b << endl;
//    cout << "a / b = " << a / b << endl;
//    cout << "a % b = " << a % b << endl;
    
    return 0;
}
