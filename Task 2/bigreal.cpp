#include "bigreal.h"
#include <bits/stdc++.h>

// Implementation file for bigReal Class

void BigReal::fill(string realnumber)
{
    integer = "";
    fraction = "";
    if (number[0] == '-')
        {
            sign = '-';
            number = number.substr(1);
        }
        else if (number[0] == '+')
        {
            sign = '+';
            number = number.substr(1);
        }
        else
            sign = '+';

        
        bool fract = false;
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == '.')
            {
                fract = true;
                i++;
            }
            if (fract)
                fraction += number[i];
            else
                integer += number[i];
        }
}

bool BigReal::isValidReal(string realnumber)
{
    int x = 0, y = 0;
    for (int i = 0; i < realnumber.size(); i++)
    {
        if (realnumber[i] == '+' or realnumber[i] == '-')
            x++;
        if (realnumber[i] == '.')
            y++;
    }
    if (x > 1 or y > 1)
        return false;

    return true;
}

BigReal::BigReal()
{
    sign = '+';
    number = "0.0";
    integer = "0";
    fraction = "0";
}

BigReal::BigReal(string realnumber)
{
    number = realnumber;
    if (isValidReal(number))
    {
        fill(number);
    }
}

void BigReal::print()
{
    if (isValidReal(number))
        cout << sign << integer << "." << fraction << endl;
    
}

int BigReal::getSize()
{
    if (isValidReal(number))
    {
        int counter = 0;
        for (int i = 0; i < number.size(); i++)
        {
            if (isdigit(number[i]))
                counter++;
        }
        return counter;
    }
    return (0);
}

char BigReal::getSign()
{
    if (isValidReal(number))
        return sign;
    return ('#');
}

void BigReal::setNumber(string realnumber)
{
    number = realnumber;
    if (isValidReal(number))
    {
        fill(number);
    }
}
