#include <iostream>
#include <string>
#include <algorithm>
#include "Bignum.h"

using namespace std;
Bignum::Bignum()
{

}

Bignum::Bignum(string s)
{
    setSign(s);
    setNumber(s);
}
Bignum::Bignum(int x)
{
    string s = to_string(x);
    setSign(s);
    setNumber(s);
}

void Bignum::setNumber(string s)
{
    string tempSign;
    unsigned long length = s.length();
    tempSign = s.substr(0, 1);

    if (tempSign == "-")
    {
        string tempNumber = s.substr(1, (length-1));
        number = tempNumber;
    }
    else if (tempSign == "+")
    {
        string tempNumber = s.substr(1, (length-1));
        number = tempNumber;
    }
    else
        number = s;
}
string Bignum::getNumber()
{
    return number;
}

void Bignum::setSign(string s)
{
    string tempSign = s.substr(0, 1);

    if (tempSign == "-")
    {
        sign = tempSign;
    }
    else if (tempSign == "+")
    {
        sign = tempSign;
    }
    else
        sign = "+";
}
string Bignum::getSign()
{
    return sign;
}

void rm0(Bignum &b)
{
    unsigned long sizeB = b.number.length();
    int c = 0;
    for (int i = 0; i < sizeB; i++)
    {
        c += 1;
        if (c == sizeB)
            break;
        if (b.number[0] == '0')
            b.number = b.number.substr(1,(sizeB - 1));
    }
}

bool Bignum::operator==(Bignum b)
{
    if (sign != b.sign)
        return false;
    if (number == b.number)
        return true;
    return false;
}

bool Bignum::operator!=(Bignum b)
{
    return !(*this == b);
}

bool Bignum::operator<(Bignum b)
{
    unsigned long n = number.length();
    unsigned long m = b.number.length();

    if (sign == b.sign)
    {
        if (sign == "+")
        {
            if (n < m)
                return true;
            else if (n > m)
                return false;
            else
            {
                for(unsigned long i = 0; i < m; i++)
                {
                    if(number[i] < b.number[i])
                        return true;
                    if(number[i] > b.number[i])
                        return false;
                }
                return false;
            }
        }
        else
        {
            if (n < m)
                return false;
            else if (n > m)
                return true;
            else
            {
                for (unsigned long i = 0; i < m; i++)
                {
                    if (number[i] < b.number[i])
                        return false;
                    if (number[i] > b.number[i])
                        return true;
                }
                return false;
            }
        }
    }
    else
    {
        if (sign == "-")
            return true;
        else
            return false;
    }
}

bool Bignum::operator>(Bignum b)
{
    if ((*this) == b)
        return false;
    else
        return !((*this) < b);
}

bool Bignum::operator<=(Bignum b)
{
    return (*this < b) || (*this == b);
}

bool Bignum::operator>=(Bignum b)
{
    return (*this > b) || (*this == b);
}

char &Bignum::operator[](int s)
{
    size_t size = number.size();
    if((s >= 0) && (s < size))
        return number[s];
    else
        throw invalid_argument("Index out of range");
}

void Bignum::printDelimeter()
{
    std::string t = "";
    int j = 0;
    for (long i = (*this).number.length() - 1; i >= 0; i--, j++)
    {
        if ((j % 3 == 0) && (j > 0))
            t += ",";
        t += (*this).number[i];
    }
    reverse(t.begin(), t.end());
    cout << (*this).getSign() << t << endl;
}

ostream &operator<<(ostream &output, Bignum c)
{
    if (c.number == "0")
        output << c.number;
    else
        output << c.sign << c.number;
    return output;
}
istream &operator>>(istream &input, Bignum &c)
{
    string temp;
    input >> temp;
    unsigned long length = temp.length();
    string tempSign = temp.substr(0, 1);

    if (tempSign == "-")
    {
        std::string tempNumber = temp.substr(1, (length-1));
        c.setNumber (tempNumber);
        c.setSign("-");
    }
    else if (tempSign == "+")
    {
        std::string tempNumber = temp.substr(1, (length-1));
        c.setNumber (tempNumber);
        c.setSign("+");
    }
    else
    {
        c.setNumber (temp);
        c.setSign("+");
    }
    return input;
}

Bignum operator+(Bignum a, Bignum b)
{
    if(a.number.length() > b.number.length())
    {
        Bignum t;
        t = b;
        b = a;
        a = t;
    }
    Bignum res;
    int tempCounter = 0;
    unsigned long n = a.number.length();
    reverse(a.number.begin(), a.number.end());
    reverse(b.number.begin(), b.number.end());
    res.setNumber(b.getNumber() + "0");
    if (a.sign == b.sign)
    {
        for (int i = 0; i < n; i++)
        {
            if (tempCounter == 1)
            {
                if (b.number[i] - 48 + a.number[i] - 48 + 1 < 10)
                {
                    res.number[i] = b.number[i] - 48 + a.number[i] - 48 + 1 + 48;
                    tempCounter = 0;
                }
                else
                {
                    res.number[i] = (b.number[i] - 48 + a.number[i] - 48 + 1) - 10 + 48;
                    tempCounter = 1;
                }

            }
            else
            {
                if (b.number[i] - 48 + a.number[i] - 48 < 10)
                {
                    res.number[i] = b.number[i] - 48 + a.number[i] - 48 + 48;
                    tempCounter = 0;
                }
                else
                {
                    res.number[i] = (b.number[i] - 48 + a.number[i] - 48) - 10 + 48;
                    tempCounter = 1;
                }
            }
        }
        if(tempCounter != 0)
        {
            for(unsigned long i = n; i < res.number.size(); i++)
            {
                int a = res.number[i] - 48 + tempCounter;
                tempCounter = a / 10;
                a = a % 10;
                res.number[i] = a + 48;
                if(tempCounter == 0)
                    break;
            }

        }
        reverse(res.number.begin(), res.number.end());
        res.setSign(a.getSign());
        rm0(res);
        return res;
    }
    else if (a.sign == "+")
    {
        b.setSign("+");
        Bignum ans = (a - b);
        reverse(ans.number.begin(), ans.number.end());
        return ans;
    }
    else
    {
        a.setSign("+");
        Bignum ans = (b - a);
        reverse(ans.number.begin(), ans.number.end());
        return ans;
    }

}

Bignum operator-(Bignum a, Bignum b)
{
    Bignum res;

    string tempBSign = b.getSign() , tempASign = a.getSign();
    b.setSign("+");
    a.setSign("+");
    if (a > b)
        res.setSign(tempASign);
    else if(b.getSign() == "+")
        res.setSign("-");
    else
        res.setSign("+");
    Bignum c , d;
    d.setNumber(b.getNumber());
    c.setNumber(a.getNumber());
    d.setSign("+");
    c.setSign("+");
    if(a.number.length() < b.number.length() || c < d)
    {
        Bignum t;
        t = b;
        b = a;
        a = t;
    }
    unsigned long n = a.number.length();
    reverse(a.number.begin(), a.number.end());
    unsigned long m = b.number.length();
    reverse(b.number.begin(), b.number.end());
    //cout << " m " << m << "  n " << n << endl;
    //if (n > m)
    //{
        res.setNumber(a.getNumber());
        unsigned long count = (n - m);
        for (int i = 0; i < count; i++)
        {
            b.number.push_back('0');
        }
    unsigned long g = 0;
        g = n;
    int tempCounter = 0;
    for (int i = 0; i < n; i++)
    {
        if (tempCounter == -1)
        {
            if (a.number[i] - 48 - (b.number[i] - 48) - 1 >= 0)
            {
                res.number[i] = a.number[i] - 48 - (b.number[i] - 48) - 1 + 48;
                tempCounter = 0;
            }
            else
            {
                res.number[i] = a.number[i] - 48 - (b.number[i] - 48) - 1 + 10 + 48;
                tempCounter = -1;
            }
        }
        else
        {
            if (a.number[i] - 48 - (b.number[i] - 48) >= 0)
            {
                res.number[i] = a.number[i] - 48 - (b.number[i] - 48) + 48;
                tempCounter = 0;
            }
            else
            {
                res.number[i] = (a.number[i] - 48 - (b.number[i] - 48) + 10 + 48);
                tempCounter = -1;
            }
        }
    }
    reverse(res.number.begin(), res.number.end());
    rm0(res);
    return res;
}

Bignum operator*(Bignum a, Bignum b)
{
    Bignum res = 0;
    string signans;
    if ((a.getSign()) == (b.getSign()))
        signans = "+";
    else
        signans = "-";
    a.setSign("+");
    b.setSign("+");
    if (a.number < b.number)
    {
        Bignum t;
        t = b;
        b = a;
        a = t;
    }
    int n = b.number.length();
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        Bignum temp1 = 0;
        for(int j = 0; j < (b.number[i] - 48); j++)
        {
            temp1 = temp1 + (a);
        }
        for (int a = 0; a < k; a++)
        {
            temp1.number += "0";
        }
        k++;
        res = res + temp1;
    }
    rm0(res);
    res.setSign(signans);
    return res;
}

Bignum operator/(Bignum a, Bignum b)
{
    if(b.getNumber() == "0")
        throw invalid_argument ("you can not do this operation.");
    Bignum c;
    c.setNumber("");
    Bignum res;
    res.setNumber("");
    string signans;
    if ((a.getSign()) == (b.getSign()))
        signans = "+";
    else
        signans = "-";

    c.setSign("+");
    b.setSign("+");
    a.setSign("+");
    for (int i = 0; i < a.number.length(); i++)
    {
        c.number += a.number[i];
        rm0(c);
        int j;
        for (j = 0; j <= 9; j++)
        {
            if ((c < (b * (j + 1))) && (c >= (b * j)))
            {
                res.number += to_string(j);
                break;
            }
        }
        c = c - (j * b);
        rm0(c);
        rm0(res);
    }
    
    res.setSign(signans);
    return res;
}

Bignum operator%(Bignum a, Bignum b)
{
    Bignum t = (a / b);
    return (a) - (t * b);
}

Bignum &operator+=(Bignum &a, Bignum b)
{
    a = a + b;
    return a;
}
Bignum &operator-=(Bignum &a, Bignum b)
{
    a = a - b;
    return a;
}
Bignum &operator*=(Bignum &a, Bignum b)
{
    a = a * b;
    return a;
}
Bignum &operator/=(Bignum &a, Bignum b)
{
    a = a / b;
    return a;
}

int& operator+=(int&, Bignum)
{
    throw invalid_argument("you can not do this operation.");
}
int& operator-=(int&, Bignum)
{
    throw invalid_argument("you can not do this operation.");
}
int& operator*=(int&, Bignum)
{
    throw invalid_argument("you can not do this operation.");
}
int& operator/=(int&, Bignum)
{
    throw invalid_argument("you can not do this operation.");
}






