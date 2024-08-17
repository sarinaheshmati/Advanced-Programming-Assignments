#ifndef Cart_h
#define Cart_h
#include <map>
#include "Product.h"
#include <list>
#include <iostream>

using namespace std;

class Cart
{
//    friend class Customer;
public:
    float get_total_price( list<Product>& );
    void add(int, int);
    void remove_item(int);
    void print( list<Product>& );
    void check_out();
    void reset();
    map<int, int>& get_items(){ return items;  };
private:
    map<int, int> items;
    
};
#endif /* Cart_h */
