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


BigReal operator +(BigReal bg2){
    string res="";
    int cnt=0;
    if (sign=='-'&& bg2.sign=='-'){
        cnt=1;
    }
    if (fraction.size()>bg2.fraction.size()){
        bg2.fraction+=string(fraction.size()-bg2.fraction.size(),'0');
    }
    else if  (fraction.size()<bg2.fraction.size())
    {
        fraction += string(bg2.fraction.size() - fraction.size(), '0');
    }
    if (integer.size()>bg2.integer.size()){
        bg2.integer=string(integer.size()-bg2.integer.size(),'0')+bg2.integer;
    }
    else if (integer.size()>bg2.integer.size()){
        integer=string(bg2.integer.size()-integer.size(),'0')+integer;
    }

    int carry=0;
    string res2="";
    for (int i=fraction.size()-1;i>=0;--i){
        int digit1=fraction[i]-'0';
        int digit2=bg2.fraction[i]-'0';
        int sum=digit1 + digit2 + carry;
        carry = sum/10;
        int digitsum = sum % 10;
        res2+= to_string(digitsum);
    }
    reverse(res2.begin(),res2.end());
    res2='.'+res2;

    string res1="";
    for (int i=integer.size()-1;i>=0;--i){
        int digit1=integer[i]-'0';
        int digit2=bg2.integer[i]-'0';
        int sum=digit1 +digit2 +carry;
        carry = sum /10;
        int digitsum= sum % 10;
        res1+= to_string(digitsum);

    }
    if (carry>0){
        res1+= to_string(carry);
    }

    reverse(res1.begin(),res1.end());
    res=res1+res2;
    if (cnt==0){
        return BigReal(res);
    }
    else {
        res='-'+res;
        return BigReal(res);
    }


}


};
