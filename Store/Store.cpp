#include "Store.h"
#include <iostream>
#include <fstream>

using namespace std;

void Store::check_out(int customer_id)
{
    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if (customer_id == it->getId())
        {
            for (auto it2 = it->getCart().get_items().begin(); it2 != it->getCart().get_items().end(); ++it2)
            {
                stock.change_count_by(it2->first, -(it2->second));
            }
            it->convert_cart_to_receipt(products);
            return;
        }
    }
    throw invalid_argument("This id does not exist.");
}
void Store::add_customer()
{
    Customer customer;
    int id;
    cout << "ID: ";
    cin >> id;
    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if (id == it->getId())
            throw invalid_argument("This id is already taken.");
    }
    customer.getId() = id;
    cout << "Name: ";
    cin >> customer.getName();
    cout << "Phone number: ";
    cin >> customer.getPhoneNumber();
    cout << "Address: ";
    cin >> customer.getAddress();
    cout << "Balance: ";
    cin >> customer.getBalance();
    customers.push_back(customer);
    cout << "adding customer was done successfully." << endl;
}
void Store::add_product()
{
    Product product;
    int id;
    int inStock;
    cout << "ID: ";
    cin >> id;
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (id == it->getId())
            throw invalid_argument("This id is already taken.");
    }
    product.getId() = id;
    cout << "Name: ";
    cin >> product.getName();
    cout << "Price: ";
    cin >> product.getPrice();
    cout << "Brand: ";
    cin >> product.getBrand();
    cout << "Expire date: ";
    cin >> product.getExpireDate();
    cout << "In stock: ";
    cin >> inStock;
    stock.get_items().insert(pair<int, int>(id, inStock));
    products.push_back(product);
    cout << "adding product was done successfully." << endl;
}
void Store::view_products()
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        for (auto it2 = stock.get_items().begin(); it2 != stock.get_items().end(); ++it2)
        {
            if (it->getId() == it2->first && it2->second > 0)
            {
                cout << "ID: " << it->getId()<< "\t" << "NAME: " << it->getName() << "\t" << "PRICE: " << it->getPrice() << "\t" << "BRAND: " << it->getBrand() << "\t" << "EXPIRE DATE: " << it->getExpireDate() << "\t" << "STOCK: " << it2->second << "\n";
            }
        }
    }
}
void Store::save_to_file()
{
    ofstream productFile("/Users/macbook/Desktop/AP/project2/project2/product.txt");
    if(!productFile)
        throw invalid_argument ("error in writing product.txt occured.");
    for(auto it = products.begin(); it != products.end(); ++it)
    {
        productFile << it->getId() << endl;
        productFile << it->getName() << endl;
        productFile << it->getPrice() << endl;
        productFile << it->getBrand() << endl;
        productFile << it->getExpireDate() << endl;
    }
    productFile.close();
    
    ofstream customerFile("/Users/macbook/Desktop/AP/project2/project2/customer.txt");
    if(!customerFile)
        throw invalid_argument ("error in writing customer.txt occured.");
    for(auto it = customers.begin(); it != customers.end(); ++it)
    {
        customerFile << it->getId() << endl;
        customerFile << it->getName() << endl;
        customerFile << it->getPhoneNumber() << endl;
        customerFile << it->getAddress() << endl;
        customerFile << it->getBalance() << endl;
    }
    customerFile.close();
    
    ofstream stockFile("/Users/macbook/Desktop/AP/project2/project2/stock.txt");
    if(!stockFile)
        throw invalid_argument ("error in writing stock.txt occured.");
    for(auto it = stock.get_items().begin(); it != stock.get_items().end(); ++it)
    {
        stockFile << it->first << endl;
        stockFile << it->second << endl;
    }
    stockFile.close();
    
    ofstream cartFile("/Users/macbook/Desktop/AP/project2/project2/cart.txt");
    if(!cartFile)
        throw invalid_argument ("error in writing cart.txt occured.");
    for(auto it = customers.begin(); it != customers.end(); ++it)
    {
        cartFile << it->getId() << endl;
        cartFile << it->getCart().get_items().size() << endl;
        for (auto it2 = it->getCart().get_items().begin(); it2 != it->getCart().get_items().end(); ++it)
        {
            cartFile << it2->first << endl;
            cartFile << it2->second << endl;
        }
    }
    cartFile.close();
    
    ofstream historyFile("/Users/macbook/Desktop/AP/project2/project2/history.txt");
    if(!historyFile)
        throw invalid_argument ("error in writing history.txt occured.");
    for(auto it = customers.begin(); it != customers.end(); ++it)
    {
        historyFile << it->getId() << endl;
        historyFile << it->getHistory().size() << endl;
        for (auto it2 = it->getHistory().begin(); it2 != it->getHistory().end(); ++it)
        {
            historyFile << it2->get_items().size() << endl;
            for (auto it3 = it2->get_items().begin(); it3 != it2->get_items().end(); ++it)
            {
                historyFile << it3->first << endl;
                historyFile << it3->second << endl;
            }
        }
    }
    historyFile.close();
}
void Store::sales_report(Date, Date)
{
    
}
