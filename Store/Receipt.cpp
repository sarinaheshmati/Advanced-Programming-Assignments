#include "Receipt.h"


float Receipt::get_total_price( list<Product> &list_of_products)
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
