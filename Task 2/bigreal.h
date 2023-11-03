// Header file for bigReal Class
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BigReal {
private:
    string number, integer = "", fraction = "";
    char sign;

    void fill(string realnumber);
    bool isValidReal(string realnumber);
public:
    BigReal();
    //~BigReal();

    BigReal(string realnumber);
    
    // BigReal(const BigReal& other);
    // BigReal &operator = (BigReal const& other);

    void print(); // display the number
    int getSize(); // return size of the number
    char getSign(); // return sign of the number
    void setNumber(string realnumber);
};
