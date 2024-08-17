#include "Stock.h"
#include <iostream>
using namespace std;

int Stock::get_count(int product_id)
{
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if (it->first == product_id)
            return it->second;
    }
    throw invalid_argument("There is no product with this id");
}

void Stock::change_count_by(int product_id, int count)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->first == product_id)
        {
            it->second += count;
            break;
        }
    }
}
