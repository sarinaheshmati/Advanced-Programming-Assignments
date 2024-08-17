#ifndef Customer_h
#define Customer_h

#include <string>
#include <list>
#include "Receipt.h"
#include "Cart.h"
#include "Product.h"

using namespace std;

class Customer
{
//    friend class Store;
public:
    void setId(int id)   {   this->id = id;  }
    int& getId()  {   return id;  }

    void setName(string name) {   this->name = name;  }
    string& getName()    {   return name;    }

    void setPhoneNumber(string phone_number)  {   this->phone_number = phone_number;  }
    string& getPhoneNumber()  {   return phone_number;    }

    void setHistory(list<Receipt> history)    {   this->history = history; }
    list<Receipt>& getHistory() {   return history; }

    void setAddress(string address) {   this->address = address;    }
    string& getAddress()   {   return address; }

    void setCart(Cart cart) {   this->cart = cart;  }
    Cart& getCart() {   return cart;    }

    void setBalance(float balance)  {   this->balance = balance;    }
    float& getBalance()    {   return balance; }
    
    void convert_cart_to_receipt( list<Product>& );
    float get_total_purchase_amount( list<Product>& );
private:
    int id;
    string name;
    string phone_number;
    list<Receipt> history;
    string address;
    Cart cart;
    float balance;
};
#endif /* Customer_h */
