#include <iostream>
#include "Date.h"
#include <stdexcept>
#include <iomanip>
#include <string>
using namespace std;

//const string Date::monthName[13] = {"", "January", "February", "March", "April", "May", "June",
//                              "July", "August", "September", "October", "November", "December"};

const unsigned int Date::daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(unsigned int y, unsigned int m, unsigned int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(const Date &dateToCopy)
{
    setYear(dateToCopy.getYear());
    setMonth(dateToCopy.getMonth());
    setDay(dateToCopy.getDay());
}

Date::Date(int intDate)
{
    int d = intDate % 100;
    intDate /= 100;
    int m = intDate % 100;
    int y = intDate / 100;
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(string stringDate)
{
    string y = stringDate.substr(0,4);
    string m = stringDate.substr(5,2);
    string d = stringDate.substr(8,2);
    
    setYear(stoi(y));
    setMonth(stoi(m));
    setDay(stoi(d));
}

void Date::setYear(unsigned int y)
{
    year = y;
}

unsigned int Date::getYear() const
{
    return year;
}

void Date::setMonth(unsigned int m)
{
    if(m >= 1 && m <= 12)
        month = m;
    else
        throw std::invalid_argument("Invalid month!");
}

unsigned int Date::getMonth() const
{
    return month;
}

void Date::setDay(unsigned int d)
{
    if(checkDay(d))
        day = d;
    else
        throw std::invalid_argument("Invalid day for current month and year!");
}

unsigned int Date::getDay() const
{
    return day;
}

bool Date::leap(unsigned int testYear)
{
    if (testYear % 400 == 0 ||
       (testYear % 4 == 0 && testYear % 100 != 0))
       return true;
    else
        return false;
}

bool Date::endOfMonth(unsigned int testDay)
{
    if(leap(year) && month == 2)
        return testDay == 29;
    else
        return testDay == Date::daysPerMonth[month];
}

void Date::print() const
{
    std::cout << year << "/" << month << "/" << day << std::endl;
}

bool Date::checkDay(unsigned int testDay) const
{

    if(testDay <= daysPerMonth[month])
        return true;
    if((month == 2 && testDay == 29) &&
       (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return true;
    return false;
}

void Date::increament()
{
    if(!endOfMonth(day))
        ++day;
    else if(month != 12)
    {
        ++month;
        day = 1;
    }
    else
    {
        ++year;
        month = day = 1;
    }
}

Date &Date::operator++()
{
    increament();
    return *this;
}

Date Date::operator++(int)
{
    Date t = *this;
    increament();
    return t;
}

Date &Date::operator+=(unsigned int daysToAdd)
{
    for(unsigned int i = 0; i < daysToAdd; ++i)
        increament();
    return *this;
}

Date::~Date()
{
//    std::cout << "Destructor of date ";
//    print();
}

Date::operator int() const
{
    return 10000 * year + 100 * month + day;
}

//Date::operator string() const
//{
//    string s;
//    s = Date::monthName[month] + " " + to_string(day) + ", " + to_string(year);
//    return s;
//}

Date::operator const char*() const
{
    static string s;
    s = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
    return s.c_str();
}

void Date::operator()(int y, int m, int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}


//ostream &operator<<(ostream &output, const Date &date)
//{
//    output << Date::monthName[date.month] << " " << date.day << ", " << date.year;
//    return output;
//}


istream &operator>>(istream &input, Date &date)
{
    input >> setw(4) >> date.year;
    input.ignore();
    input >> setw(2) >> date.month;
    input.ignore();
    input >> setw(2) >> date.day;
    return input;
}
