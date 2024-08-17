#include <iostream>
#include <iomanip>
#include "Cart.h"


float Cart::get_total_price( list<Product> &list_of_products)
{
    float total_price = 0;
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        for (auto it2 = list_of_products.begin(); it2 != list_of_products.begin(); ++it2)
        {
            if (it2->getId() == it->first)
            {
                total_price += (it->second) * (it2->getPrice());
                break;
            }
        }
    }
    return total_price;
}
void Cart::add(int product_id, int product_count)
{
    items.insert(pair<int, int>(product_id, product_count));
}
void Cart::remove_item(int product_id)
{
    items.erase(product_id);
}
void Cart::print( list<Product> &list_of_products)
{
    for(auto it = items.begin(); it!= items.end(); ++it)
    {
        for (auto it2 = list_of_products.begin(); it2 != list_of_products.end(); ++it)
        {
            if (it->first == it2->getId())
            {
                cout << "product id:" << setw(10) << it2->getId()
                     << "product name:" << setw(10) << it2->getName()
                     << "product brand:" << setw(10) << it2->getBrand()
                     << "product price:" << setw(10) << it2->getPrice()
                     << "product expire date:" << setw(10) << it2->getExpireDate()
                     << "product count:" << setw(10) << it->second;
            }
        }
    }
}
//void Cart::check_out()
//{
//    
//}
void Cart::reset()
{
    items.clear();
}
