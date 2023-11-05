// Header file for bigReal Class
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BigReal
{
private:
    string number, integer, fraction;
    char sign;

    void fill(string realnumber);
    bool isValidReal(string realnumber);

public:
    BigReal();
    BigReal(string realnumber);
    BigReal(const BigReal& other); // Copy Constructor
    BigReal &operator = (BigReal const& other); // Overloading assignment operator
    ~BigReal();


    void print();   // display the number
    int getSize();  // return size of the number
    char getSign(); // return sign of the number
    void setNumber(string realnumber);

    bool operator>(BigReal bg1); // Overloading operator >
    bool operator<(BigReal bg1); // Overloading operator <
    bool operator==(BigReal bg1); // Overloading operator ==
    BigReal operator+(BigReal bg2); // Overloading operator +

    friend ostream& operator << (ostream& out, BigReal num); // Overloading operator <<
};
