#include <iostream>
#include <fstream>
#include "Date.h"
#include "Product.h"
#include "Receipt.h"
#include "Stock.h"
#include "Store.h"
#include "Cart.h"

using namespace std;

void read_file (Store&);
int main()
{
    Store store;
    read_file(store);
    cout << "FUNCTIONS TO DO:\n 1-CHECKOUT\n 2-ADD CUSTOMER\n 3-ADD PRODUCT\n 4-VIEW PRODUCTS\n 5-SAVE TO FILE AND EXIT\n 6-SALES REPORT\n 7-CUSTOMER PANEL\n 8-STOCK\n ENTER THE NUMBER OF YOUR CHOICE:\t";
    int in;
    while (cin >> in)
    {
        if (in == 5)
        {
            store.save_to_file();
            break;
        }
        else if (in == 1)
        {
            cout << "please enter the ckecking out customer's id:\t";
            int customerId;
            cin >> customerId;
            bool checkId = false;
            for (auto it = store.getCustomers().begin(); it != store.getCustomers().end(); ++it)
            {
                if (it->getId() == customerId)
                {
                    store.check_out(customerId);
                    checkId = true;
                    break;
                }
            }
            if (checkId == false)
                throw invalid_argument ("this id does not exist.");
        }
        else if (in == 2)
        {
            store.add_customer();
        }
        else if (in == 3)
        {
            store.add_product();
        }
        else if (in == 4)
        {
            store.view_products();
        }
        else if (in == 6)
        {
            Date date1;
            Date date2;
            cout << "please enter two dates that makes your time period:\t";
            cin >> date1 >> date2;
            store.sales_report(date1, date2);
        }
        else if (in == 7)
        {
            cout << "FUNCTIONS TO DO:\n 1-ADD AN ITEM TO CART\n 2-REMOVE AN ITEM FROM CART\n 3-PRINT CART\n 4-TOTAL CURRENT PURCHASE AMOUNT\n 5-RESET CART\n 6-TOTAL PURCHASE AMOUNT\n 7-RETURN TO HOME PAGE\n ENTER THE NUMBER OF YOUR CHOICE:\t";
            int customerId2;
            cout << "please enter customer's id:\t";
            cin >> customerId2;
            bool checkId2 = false;
            for (auto it = store.getCustomers().begin(); it != store.getCustomers().end(); ++it)
            {
                if (it->getId() == customerId2)
                {
                    checkId2 = true;
                    int in2;
                    while (cin >> in2)
                    {
                        if(in2 == 7)
                        {
                            break;
                        }
                        else if (in2 == 1)
                        {
                            int productId;
                            int productCount;
                            bool checkPId = false;
                            cin >> productId;
                            for (auto it2 = store.getProducts().begin(); it2 != store.getProducts().end(); ++it2)
                            {
                                if (it2->getId() == productId)
                                {
                                    checkPId = true;
                                    cin >> productCount;
                                    it->getCart().add(productId, productCount);
                                    break;
                                }
                            }
                            if (!checkPId)
                                throw invalid_argument ("this id does not exist.");
                        }
                        else if (in2 == 2)
                        {
                            int productId;
                            bool checkPId = false;
                            cin >> productId;
                            for (auto it2 = store.getProducts().begin(); it2 != store.getProducts().end(); ++it2)
                            {
                                if (it2->getId() == productId)
                                {
                                    checkPId = true;
                                    it->getCart().remove_item(productId);
                                    break;
                                }
                            }
                            if (!checkPId)
                                throw invalid_argument ("this id does not exist.");
                        }
                        else if (in2 == 3)
                        {
                            it->getCart().print(store.getProducts());
                        }
                        else if (in2 == 4)
                        {
                            it->getCart().get_total_price(store.getProducts());
                        }
                        else if (in2 == 5)
                        {
                            it->getCart().reset();
                        }
                        else if (in2 == 6)
                        {
                            it->get_total_purchase_amount(store.getProducts());
                        }
                        cout << "FUNCTIONS TO DO:\n 1-ADD AN ITEM TO CART\n 2-REMOVE AN ITEM FROM CART\n 3-PRINT CART\n 4-TOTAL CURRENT PURCHASE AMOUNT\n 5-RESET CART\n 6-TOTAL PURCHASE AMOUNT\n 7-RETURN TO HOME PAGE\n ENTER THE NUMBER OF YOUR CHOICE:\t";
                    }
                }
            }
            if (checkId2 == false)
                throw invalid_argument ("this id does not exist.");
        }
        else if (in == 8)
        {
            cout << "FUNCTIONS TO DO:\n 1-CHANGE COUNT BY ID\n 2-GET COUNT BY ID\n 3-RETURN TO HOME PAGE\n ENTER THE NUMBER OF YOUR CHOICE:\t";
            int in3;
            while (cin >> in3)
            {
                if (in3 == 3)
                {
                    break;
                }
                else if (in3 == 1)
                {
                    int productId;
                    int productCount;
                    bool checkPId = false;
                    cin >> productId;
                    for (auto it4 = store.getProducts().begin(); it4 != store.getProducts().end(); ++it4)
                    {
                        if (it4->getId() == productId)
                        {
                            checkPId = true;
                            cin >> productCount;
                            store.getStock().change_count_by(productId, productCount);
                            break;
                        }
                    }
                    if (!checkPId)
                        throw invalid_argument ("this id does not exist.");
                }
                else if (in3 == 2)
                {
                    int productId;
                    bool checkPId = false;
                    cin >> productId;
                    for (auto it5 = store.getProducts().begin(); it5 != store.getProducts().end(); ++it5)
                    {
                        if (it5->getId() == productId)
                        {
                            checkPId = true;
                            store.getStock().get_count(productId);
                            break;
                        }
                    }
                    if (!checkPId)
                        throw invalid_argument ("this id does not exist.");
                }
                cout << "FUNCTIONS TO DO:\n 1-CHANGE COUNT BY ID\n 2-GET COUNT BY ID\n 3-RETURN TO HOME PAGE\n ENTER THE NUMBER OF YOUR CHOICE:\t";
            }
        }
        cout << "FUNCTIONS TO DO:\n 1-CHECKOUT\n 2-ADD CUSTOMER\n 3-ADD PRODUCT\n 4-VIEW PRODUCTS\n 5-SAVE TO FILE AND EXIT\n 6-SALES REPORT\n 7-CUSTOMER PANEL\n 8-STOCK\n ENTER THE NUMBER OF YOUR CHOICE:\t";
    }
}

void read_file (Store &store)
{
    ifstream productFile("/Users/macbook/Desktop/AP/project2/project2/product.txt");
    if(!productFile)
        throw invalid_argument("error in opening product.txt occurred.");
    Product product;
    while (productFile >> product.getId())
    {
        productFile >> product.getName();
//        getline(productFile, product.getName());
        productFile >> product.getPrice();
        productFile >> product.getBrand();
//        getline(productFile, product.getBrand());
        string date;
        productFile >> date;
        product.getExpireDate() = date;
        store.getProducts().push_back(product);
    }
//    store.getProducts().pop_back(product);
    productFile.close();
    
    ifstream customerFile("/Users/macbook/Desktop/AP/project2/project2/customer.txt");
    if(!customerFile)
        throw invalid_argument("error in opening customer.txt occurred.");
    Customer customer;
    while (customerFile >> customer.getId())
    {
        string name;
        string phoneNumber;
        string address;
        customerFile >> name;
        customerFile >> phoneNumber;
        customerFile >> address;
        customer.setName(name);
        customer.setPhoneNumber(phoneNumber);
        customer.setAddress(address);
//        getline(customerFile, customer.getName());
//        getline(customerFile, customer.getPhoneNumber());
//        getline(customerFile, customer.getAddress());
        customerFile >> customer.getBalance();
//        store.getCustomers().push_back(customer);
    }
    customerFile.close();
    
    ifstream stockFile("/Users/macbook/Desktop/AP/project2/project2/stock.txt");
    if(!stockFile)
        throw invalid_argument("error in opening stock.txt occurred.");
    int id;
    while (stockFile >> id)
    {
        int count;
        stockFile >> count;
        store.getStock().get_items().insert(pair<int, int>(id, count));
    }
    stockFile.close();
    
    ifstream cartFile("/Users/macbook/Desktop/AP/project2/project2/cart.txt");
    if(!cartFile)
        throw invalid_argument("error in opening cart.txt occurred.");
    int customerId;
    while (cartFile >> customerId)
    {
        int countOfPair;
        cartFile >> countOfPair;
        for (auto it = store.getCustomers().begin(); it != store.getCustomers().end(); ++it)
        {
            if (it->getId() == customerId)
            {
                for (int i = 0; i <=countOfPair; ++i)
                {
                    int productId;
                    int productCount;
                    cartFile >> productId;
                    cartFile >> productCount;
                    it->getCart().get_items().insert(pair<int, int>(productId, productCount));
                }
                break;
            }
        }
    }
    cartFile.close();
    
    ifstream historyFile("/Users/macbook/Desktop/AP/project2/project2/history.txt");
    if(!historyFile)
        throw invalid_argument("error in opening history.txt occurred.");
    Receipt receipt;
    int customerId2;
    while (historyFile >> customerId2)
    {
        int countOfReceipt;
        int countOfPair;
        historyFile >> countOfReceipt;
        for (auto it = store.getCustomers().begin(); it != store.getCustomers().end(); ++it)
        {
            if (it->getId() == customerId2)
            {
                for (int i = 0; i <= countOfReceipt; ++i)
                {
                    historyFile >> countOfPair;
                    for (int j = 0; j <= countOfPair; ++j)
                    {
                        int productId;
                        int productCount;
                        historyFile >> productId;
                        historyFile >> productCount;
                        receipt.get_items().insert(pair<int, int>(productId, productCount));
                    }
                    string date;
                    historyFile >> date;
                    receipt.setDate(date);
                    it->getHistory().push_back(receipt);
                }
                break;
            }
        }
    }
    historyFile.close();
    
}
