Store Management System
Overview
This project is a C++ implementation of a simple Store Management System. The system is designed to manage products, customers, stock, carts, receipts, and sales. It provides functionalities for adding products, managing customer carts, checking out, and generating sales reports. The project is organized into several classes, each representing a key component of the system.

Classes
1. Product
The Product class represents an item available for sale in the store.

Private Members:
int id: Unique identifier for the product.
std::string name: Name of the product.
float price: Price of the product.
std::string brand: Brand of the product.
Date expire_date: Expiration date of the product.
Public Members:
void setId(int id): Sets the product ID.
int& getId(): Gets the product ID.
void setName(std::string name): Sets the product name.
std::string& getName(): Gets the product name.
void setPrice(float price): Sets the product price.
float& getPrice(): Gets the product price.
void setBrand(std::string brand): Sets the product brand.
std::string& getBrand(): Gets the product brand.
void setExpireDate(Date expire_date): Sets the expiration date.
Date& getExpireDate(): Gets the expiration date.
2. Date
The Date class represents a specific date and provides various date-related functionalities.

Private Members:
unsigned int year: Year of the date.
unsigned int month: Month of the date.
unsigned int day: Day of the date.
void increment(): Increments the date by one day.
bool checkDay(unsigned int) const: Checks if a day is valid for the given month and year.
Public Members:
explicit Date(unsigned int year = 1900, unsigned int month = 1, unsigned int day = 1): Constructor with default values.
Date(const Date&): Copy constructor.
Date(int): Constructor from an integer.
Date(std::string): Constructor from a string.
void setYear(unsigned int): Sets the year.
unsigned int getYear() const: Gets the year.
void setMonth(unsigned int): Sets the month.
unsigned int getMonth() const: Gets the month.
void setDay(unsigned int): Sets the day.
unsigned int getDay() const: Gets the day.
static bool leap(unsigned int): Checks if a year is a leap year.
bool endOfMonth(unsigned int): Checks if the date is the end of the month.
Date &operator++(): Prefix increment operator.
Date operator++(int): Postfix increment operator.
Date &operator+=(unsigned int): Adds days to the date.
void print() const: Prints the date.
explicit operator int() const: Converts the date to an integer.
operator const char*() const: Converts the date to a C-string.
void operator()(int year = 1900, int month = 1, int day = 1): Function call operator to reset the date.
~Date(): Destructor.
3. Receipt
The Receipt class represents a receipt for purchased items.

Private Members:
Date date: The date of the receipt.
std::map<int, int> items: Map of product IDs to quantities purchased.
Public Members:
void setItems(std::map<int, int> items): Sets the purchased items.
std::map<int, int>& get_items(): Gets the purchased items.
void setDate(Date date): Sets the date of the receipt.
Date& getDate(): Gets the date of the receipt.
float get_total_price(std::list<Product>&): Calculates the total price of the receipt.
4. Stock
The Stock class manages the stock of products in the store.

Private Members:
std::map<int, int> items: Map of product IDs to quantities in stock.
Public Members:
int get_count(int): Gets the quantity of a specific product in stock.
void change_count_by(int, int): Changes the quantity of a specific product in stock.
std::map<int, int>& get_items(): Gets the map of items in stock.
5. Cart
The Cart class represents a shopping cart for a customer.

Private Members:
std::map<int, int> items: Map of product IDs to quantities in the cart.
Public Members:
float get_total_price(std::list<Product>&): Calculates the total price of items in the cart.
void add(int, int): Adds a product to the cart.
void remove_item(int): Removes a product from the cart.
void print(std::list<Product>&): Prints the contents of the cart.
void check_out(): Checks out the cart.
void reset(): Resets the cart.
std::map<int, int>& get_items(): Gets the map of items in the cart.
6. Customer
The Customer class represents a customer of the store.

Private Members:
int id: Unique identifier for the customer.
std::string name: Name of the customer.
std::string phone_number: Phone number of the customer.
std::list<Receipt> history: Purchase history of the customer.
std::string address: Address of the customer.
Cart cart: Shopping cart of the customer.
float balance: Account balance of the customer.
Public Members:
void setId(int id): Sets the customer ID.
int& getId(): Gets the customer ID.
void setName(std::string name): Sets the customer name.
std::string& getName(): Gets the customer name.
void setPhoneNumber(std::string phone_number): Sets the customer phone number.
std::string& getPhoneNumber(): Gets the customer phone number.
void setHistory(std::list<Receipt> history): Sets the purchase history.
std::list<Receipt>& getHistory(): Gets the purchase history.
void setAddress(std::string address): Sets the customer address.
std::string& getAddress(): Gets the customer address.
void setCart(Cart cart): Sets the customer cart.
Cart& getCart(): Gets the customer cart.
void setBalance(float balance): Sets the customer balance.
float& getBalance(): Gets the customer balance.
void convert_cart_to_receipt(std::list<Product>&): Converts the cart to a receipt.
float get_total_purchase_amount(std::list<Product>&): Calculates the total purchase amount.
7. Store
The Store class manages the overall store operations, including products, customers, and stock.

Private Members:
std::list<Product> products: List of products available in the store.
std::list<Customer> customers: List of customers of the store.
Stock stock: Stock of products.
Public Members:
void setProducts(std::list<Product> products): Sets the list of products.
std::list<Product>& getProducts(): Gets the list of products.
void setStock(Stock stock): Sets the stock.
Stock& getStock(): Gets the stock.
void setCustomers(std::list<Customer> customers): Sets the list of customers.
std::list<Customer>& getCustomers(): Gets the list of customers.
void check_out(int): Processes the checkout for a customer.
void add_customer(): Adds a new customer to the store.
void add_product(): Adds a new product to the store.
void view_products(): Displays all products in the store.
void save_to_file(): Saves the store data to a file.
void sales_report(Date, Date): Generates a sales report for a specific date range.
Usage
This project is designed to be used in a C++ environment. To compile and run the project, ensure that all necessary files are included in your build, and use a C++ compiler like g++.

Example usage:

cpp
Copy code
Store store;

// Add products, customers, and perform various operations as needed.
store.add_product();
store.add_customer();
store.view_products();
store.check_out(customerId);
store.sales_report(startDate, endDate);
License
This project is licensed under the MIT License. See the LICENSE file for more details.

Contributing
Contributions are welcome! Please submit a pull request or open an issue for any bug fixes or enhancements.
