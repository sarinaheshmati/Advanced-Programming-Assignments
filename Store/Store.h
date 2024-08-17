#ifndef Store_h
#define Store_h
#include "Product.h"
#include "Customer.h"
#include "Stock.h"
#include <list>
#include <iostream>
using namespace std;

class Store
{
public:
    void setProducts(list<Product> products) {   this->products = products;  }
    list<Product>& getProducts()    {   return products;    }

    void setStock(Stock stock)   {   this->stock = stock;    }
    Stock& getStock()   {   return stock;   }

    void setCustomers(list<Customer> customers)  {   this->customers = customers;   }
    list<Customer>& getCustomers()   {   return customers;   }
    
    void check_out(int);
    void add_customer();
    void add_product();
    void view_products();
    void save_to_file();
    void sales_report(Date, Date);
private:
    list<Product> products;
    list<Customer> customers;
    Stock stock;
};

#endif /* Store_h */
