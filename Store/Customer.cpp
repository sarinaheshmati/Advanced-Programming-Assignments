#include "Customer.h"
#include <ctime>

void Customer::convert_cart_to_receipt( list<Product> &list_of_product)
{
    Date date;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date.setYear(1900 + ltm->tm_year);
    date.setMonth(1 + ltm->tm_mon);
    date.setDay(ltm->tm_mday);
    Receipt receipt;
    receipt.getDate() = date;
    if (cart.get_total_price(list_of_product) > balance)
        throw invalid_argument("Not enough balance.");
    for (auto it = cart.get_items().begin(); it != cart.get_items().end(); ++it)
    {
        receipt.get_items().insert(pair<int, int>(it->first, it->second));
    }
    balance -= cart.get_total_price(list_of_product);
    cart.reset();
    history.push_back(receipt);
}
float Customer::get_total_purchase_amount( list<Product> &list_of_product)
{
    float total_purchase_amount = 0;
    for (auto it = history.begin(); it != history.end(); ++it)
    {
        total_purchase_amount += it->get_total_price(list_of_product);
    }
    return total_purchase_amount;
}
