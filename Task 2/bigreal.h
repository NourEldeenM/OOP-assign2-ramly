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
     bool operator >(BigReal bg1){
        if (sign=='+'&& bg1.sign=='+') {
            if (integer.size() > bg1.integer.size())
                return true;
            if (integer.size() == bg1.integer.size()) {
                if (integer > bg1.integer)
                    return true;
            }
            if (integer == bg1.integer) {
                if (fraction > bg1.fraction)
                    return true;
            }
            return false;
        }
        if (sign=='+'&& bg1.sign=='-')
            return true;
        if (sign=='-'&& bg1.sign=='-'){
            if (integer.size() < bg1.integer.size())
                return true;
            if (integer.size() == bg1.integer.size()) {
                if (integer < bg1.integer)
                    return true;
            }
            if (integer == bg1.integer) {
                if (fraction < bg1.fraction)
                    return true;
            }
            return false;
        }
    }
    bool operator <(BigReal bg1){
        if (sign=='+'&& bg1.sign=='+') {
            if (integer.size() < bg1.integer.size())
                return true;
            if (integer.size() == bg1.integer.size()) {
                if (integer < bg1.integer)
                    return true;
            }
            if (integer == bg1.integer) {
                if (fraction < bg1.fraction)
                    return true;
            }
            return false;
        }
        if (sign=='-'&& bg1.sign=='+')
            return true;
        if (sign=='-'&& bg1.sign=='-'){
            if (integer.size() > bg1.integer.size())
                return true;
            if (integer.size() == bg1.integer.size()) {
                if (integer > bg1.integer)
                    return true;
            }
            if (integer == bg1.integer) {
                if (fraction > bg1.fraction)
                    return true;
            }
            return false;
        }
    }
    bool operator ==(BigReal bg1){
        if (sign==bg1.sign){
            if (integer.size()==bg1.integer.size())
                if (integer==bg1.integer)
                    if (fraction==bg1.fraction)
                        return true;
        }
        return false;
    }

};
