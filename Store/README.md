# Store Management System

## Overview

This C++ project implements a Store Management System that handles products, customers, stock, carts, and sales operations. It provides functionalities such as adding products, managing customer carts, processing checkouts, and generating sales reports.

## Classes

### `Product`
Represents a store item.
- **Private Members**: `id`, `name`, `price`, `brand`, `expire_date` (as `Date`).
- **Public Methods**: Setters and getters for all private members.

### `Date`
Handles date-related operations.
- **Private Members**: `year`, `month`, `day`.
- **Public Methods**: Constructors, date validation, increment operations, and format conversion.

### `Receipt`
Stores purchase details.
- **Private Members**: `date` (as `Date`), `items` (product ID and quantity map).
- **Public Methods**: Setters and getters, `get_total_price` to calculate the total price of items.

### `Stock`
Manages product stock.
- **Private Members**: `items` (product ID and quantity map).
- **Public Methods**: Get item count, modify item quantities.

### `Cart`
Represents a customer's shopping cart.
- **Private Members**: `items` (product ID and quantity map).
- **Public Methods**: Calculate total price, add/remove items, print contents, checkout, reset.

### `Customer`
Represents a store customer.
- **Private Members**: `id`, `name`, `phone_number`, `address`, `cart` (as `Cart`), `balance`, and `history` (as a list of `Receipt`).
- **Public Methods**: Setters and getters, convert cart to receipt, calculate total purchase amount.

### `Store`
Manages overall store operations.
- **Private Members**: `products` (list of `Product`), `customers` (list of `Customer`), `stock` (as `Stock`).
- **Public Methods**: Manage products, customers, checkout, view products, save data, generate sales reports.

## Usage

Compile and run the project using a C++ compiler like `g++`. Example usage:

```cpp
Store store;
store.add_product();
store.add_customer();
store.check_out(customerId);
store.sales_report(startDate, endDate);
```

## License

Licensed under the MIT License. See `LICENSE` for details.

## Contributing

Contributions are welcome! Submit a pull request or open an issue for any enhancements or bug fixes.

---

This `README.md` provides a concise overview of the project and its key components.
