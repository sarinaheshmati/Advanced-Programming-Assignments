#ifndef Receipt_h
#define Receipt_h
#include "Date.h"
#include "Product.h"
#include <map>
#include <list>
class Receipt
{
//    friend class Customer;
public:
    void setItems(map<int, int> items)  {   this->items = items;    }
    map<int, int>& get_items()  { return items; };

    void setDate(Date date)    {   this->date = date;  }
    Date& getDate()    {   return date;    }
    
    float get_total_price( list<Product>& );
private:
    Date date;
    map<int, int> items;
};

#endif /* Receipt_h */
