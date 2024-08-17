# Bignum Class

## Overview

This C++ project defines a `Bignum` class for performing arithmetic operations on large integers that exceed the standard data type limits. The class supports various operations such as addition, subtraction, multiplication, division, and modulus.

## Class

### `Bignum`
Represents a large integer with support for basic arithmetic and comparison operations.

- **Private Members**:
  - `std::string number`: The numeric value of the `Bignum`.
  - `std::string sign`: The sign of the number (`+` or `-`).

- **Public Methods**:
  - **Constructors**:
    - `Bignum()`: Default constructor.
    - `explicit Bignum(std::string)`: Initializes `Bignum` from a string.
    - `Bignum(int)`: Initializes `Bignum` from an integer.
  - `void setNumber(std::string)`: Sets the numeric value.
  - `std::string getNumber()`: Gets the numeric value.
  - `void setSign(std::string)`: Sets the sign.
  - `std::string getSign()`: Gets the sign.
  - **Comparison Operators**:
    - `bool operator==(Bignum)`, `bool operator!=(Bignum)`, `bool operator<(Bignum)`, `bool operator>(Bignum)`, `bool operator<=(Bignum)`, `bool operator>=(Bignum)`.
  - `char &operator[](int)`: Access individual digits.
  - `void printDelimeter()`: Prints a delimiter (implementation-specific).

- **Friend Functions**:
  - **I/O Operators**: `std::ostream &operator<<(std::ostream&, Bignum)` and `std::istream &operator>>(std::istream&, Bignum&)`.
  - **Arithmetic Operators**: `Bignum operator+(Bignum, Bignum)`, `Bignum operator-(Bignum, Bignum)`, `Bignum operator*(Bignum, Bignum)`, `Bignum operator/(Bignum, Bignum)`, `Bignum operator%(Bignum, Bignum)`.
  - **Compound Assignment Operators**: `Bignum& operator+=(Bignum&, Bignum)`, `Bignum& operator-=(Bignum&, Bignum)`, `Bignum& operator*=(Bignum&, Bignum)`, `Bignum& operator/=(Bignum&, Bignum)`.
  - **Helper Functions**: `void rm0(Bignum&)` to remove leading zeros.

## Example: Multiplication Operator

The `operator*` function multiplies two `Bignum` objects. It adjusts signs, multiplies digit-by-digit, and sums the intermediate results.

```cpp
Bignum operator*(Bignum a, Bignum b) {
    Bignum res = 0;
    res.setSign((a.getSign() == b.getSign()) ? "+" : "-");
    a.setSign("+");
    b.setSign("+");

    if (a.number < b.number) std::swap(a, b);

    int n = b.number.length(), k = 0;
    for (int i = n - 1; i >= 0; i--) {
        Bignum temp1 = 0;
        for(int j = 0; j < (b.number[i] - '0'); j++) temp1 = temp1 + a;
        temp1.number.append(k++, '0');
        res = res + temp1;
    }
    rm0(res);
    return res;
}
```
