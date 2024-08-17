#ifndef Product_h
#define Product_h
#include <string>
#include "Date.h"

using namespace std;


class Product
{
//    friend class Receipt;
//    friend class Cart;
//    friend class Store;
public:
    void setId(int id)  {  this->id = id;  }
    int& getId()  {  return id;  }

    void setName(string name)   {   this->name = name;  }
    string& getName() {   return name;    }

    void setPrice(float price)  {   this->price = price;    }
    float& getPrice() {   return price;   }

    void setBrand(string brand) {   this->brand = brand;    }
    string& getBrand() {   return brand;   }
    
    void setExpireDate(Date expire_date)  {   this->expire_date = expire_date;  }
    Date& getExpireDate()  {   return expire_date; }
private:
    int id;
    string name;
    float price;
    string brand;
    Date expire_date;
};

#endif /* Product_h */
