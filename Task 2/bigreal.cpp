#include "bigreal.h"
#include <bits/stdc++.h>

// Implementation file for bigReal Class

void BigReal::fill(string realnumber)
{
    // Assigning the sign variable the sign of the number
    integer = "";
    fraction = "";
    if (realnumber[0] == '-')
    {
        sign = '-';
        realnumber = realnumber.substr(1);
    }
    else if (realnumber[0] == '+')
    {
        sign = '+';
        realnumber = realnumber.substr(1);
    }
    else
        sign = '+';

    // Filling the integer string with the values before the decimal
    // and fraction string with the values after the decimal
    bool fract = false;
    for (int i = 0; i < realnumber.size(); i++)
    {
        if (realnumber[i] == '.')
        {
            fract = true;
            i++;
        }
        if (fract)
            fraction += realnumber[i];
        else
            integer += realnumber[i];
    }

    // Removing extra zeros at the LHS of the string integer
    // as they are not important.
    int zeros = 0;
    for (int i = 0; i < integer.size(); i++)
    {
        if (integer[i] != '0')
            break;
        else
            zeros++;
    }
    integer.erase(0, zeros);
    // If the string integer is empty, add 0 to it.
    // ex: (.234 = 0.234)
    if (integer.size() == 0)
        integer += '0';

    // Removing extra zeros at the RHS of the string integer
    // as they are not important
    zeros = 0;
    for (int i = fraction.size() - 1; i >= 0; i--)
    {
        if (fraction[i] != '0')
            break;
        else
            zeros++;
    }
    reverse(fraction.begin(), fraction.end());
    fraction.erase(0, zeros);
    reverse(fraction.begin(), fraction.end());
    // If the string fraction is empty, add 0 to it.
    // ex: (123. = 123.0)
    if (fraction.size() == 0)
        fraction += '0';

    // Update the main number.
    number = realnumber;
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
    if (isValidReal(realnumber))
    {
        fill(realnumber);
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
        for (int i = 0; i < integer.size(); i++)
            counter++;

        for (int i = 0; i < fraction.size(); i++)
            counter++;

        counter -= 2;
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
