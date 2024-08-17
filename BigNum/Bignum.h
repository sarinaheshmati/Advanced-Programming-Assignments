//
//  Bignum.h
//  project1
//
//  Created by MacBook on 2/15/1401 AP.
//


#ifndef Bignum_h
#define Bignum_h
#include <string>

using namespace std;

class Bignum
{
    friend std::ostream &operator<<(std::ostream&, Bignum);
    friend std::istream &operator>>(std::istream&, Bignum&);
    
    friend void rm0(Bignum&);
    
    friend Bignum operator+(Bignum, Bignum);
    friend Bignum operator-(Bignum, Bignum);
    friend Bignum operator*(Bignum, Bignum);
    friend Bignum operator/(Bignum, Bignum);
    friend Bignum operator%(Bignum, Bignum);

    friend int& operator+=(int&, Bignum);
    friend int& operator-=(int&, Bignum);
    friend int& operator*=(int&, Bignum);
    friend int& operator/=(int&, Bignum);
    
    friend Bignum& operator+=(Bignum&, Bignum);
    friend Bignum& operator-=(Bignum&, Bignum);
    friend Bignum& operator*=(Bignum&, Bignum);
    friend Bignum& operator/=(Bignum&, Bignum);

public:
    Bignum();
    explicit Bignum(std::string);
    Bignum(int);

    void setNumber(std::string);
    std::string getNumber();

    void setSign(std::string);
    std::string getSign();

    bool operator==(Bignum);
    bool operator!=(Bignum);

    bool operator<(Bignum);
    bool operator>(Bignum);
    bool operator<=(Bignum);
    bool operator>=(Bignum);

    char &operator[](int);

    void printDelimeter();
private:
    std::string number;
    std::string sign;
};
#endif /* Bignum_h */
