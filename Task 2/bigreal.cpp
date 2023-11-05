// Implementation file for bigReal Class
// File: bigreal.cpp
// Purpose: Implementation file for Assignment2 Task2
// Author: Sara Mohamed Zaghloul / Maryam Omar / Nour Eldeen Mohamed
// Section: S5/6
// ID: 20221070 - 20220365 - 20221145
// TA: Eng. Maya / Eng. Nardeen
// Date: 23 Oct 2023

#include "bigreal.h"
#include <bits/stdc++.h>

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

BigReal::~BigReal()
{
}

BigReal::BigReal(const BigReal &other)
{
    sign = other.sign;
    integer = other.integer;
    fraction = other.fraction;
    number = other.number;
}

BigReal &BigReal::operator=(BigReal const &other)
{
    // TODO: insert return statement here
    if (this != &other)
    {
        sign = other.sign;
        integer = other.integer;
        fraction = other.fraction;
        number = other.number;
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

bool BigReal::operator>(BigReal bg1)
{

    if (sign == '+' && bg1.sign == '+')
    {
        if (integer.size() > bg1.integer.size())
            return true;
        if (integer.size() == bg1.integer.size())
        {
            if (integer > bg1.integer)
                return true;
        }
        if (integer == bg1.integer)
        {
            if (fraction > bg1.fraction)
                return true;
        }
        return false;
    }
    if (sign == '+' && bg1.sign == '-')
        return true;
    if (sign == '-' && bg1.sign == '-')
    {
        if (integer.size() < bg1.integer.size())
            return true;
        if (integer.size() == bg1.integer.size())
        {
            if (integer < bg1.integer)
                return true;
        }
        if (integer == bg1.integer)
        {
            if (fraction < bg1.fraction)
                return true;
        }
        return false;
    }
}

bool BigReal::operator<(BigReal bg1)
{
    if (sign == '+' && bg1.sign == '+')
    {
        if (integer.size() < bg1.integer.size())
            return true;
        if (integer.size() == bg1.integer.size())
        {
            if (integer < bg1.integer)
                return true;
        }
        if (integer == bg1.integer)
        {
            if (fraction < bg1.fraction)
                return true;
        }
        return false;
    }
    if (sign == '-' && bg1.sign == '+')
        return true;
    if (sign == '-' && bg1.sign == '-')
    {
        if (integer.size() > bg1.integer.size())
            return true;
        if (integer.size() == bg1.integer.size())
        {
            if (integer > bg1.integer)
                return true;
        }
        if (integer == bg1.integer)
        {
            if (fraction > bg1.fraction)
                return true;
        }
        return false;
    }
}

bool BigReal::operator==(BigReal bg1)
{
    if (sign == bg1.sign)
    {
        if (integer.size() == bg1.integer.size())
            if (integer == bg1.integer)
                if (fraction == bg1.fraction)
                    return true;
    }
    return false;
}

BigReal BigReal::operator+(BigReal bg2)
{
    string res = "";
    int cnt = 0;
    if (sign == '-' && bg2.sign == '-')
        cnt = 1;

    if (fraction.size() > bg2.fraction.size())
        bg2.fraction += string(fraction.size() - bg2.fraction.size(), '0');
    else if (fraction.size() < bg2.fraction.size())
        fraction += string(bg2.fraction.size() - fraction.size(), '0');
    if (integer.size() > bg2.integer.size())
        bg2.integer = string(integer.size() - bg2.integer.size(), '0') + bg2.integer;
    else if (integer.size() > bg2.integer.size())
        integer = string(bg2.integer.size() - integer.size(), '0') + integer;

    int carry = 0;
    string res2 = "";
    for (int i = fraction.size() - 1; i >= 0; --i)
    {
        int digit1 = fraction[i] - '0';
        int digit2 = bg2.fraction[i] - '0';
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digitsum = sum % 10;
        res2 += to_string(digitsum);
    }
    reverse(res2.begin(), res2.end());
    res2 = '.' + res2;

    string res1 = "";
    for (int i = integer.size() - 1; i >= 0; --i)
    {
        int digit1 = integer[i] - '0';
        int digit2 = bg2.integer[i] - '0';
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digitsum = sum % 10;
        res1 += to_string(digitsum);
    }
    if (carry > 0)
        res1 += to_string(carry);

    reverse(res1.begin(), res1.end());
    res = res1 + res2;
    if (cnt == 0)
        return BigReal(res);
    else
    {
        res = '-' + res;
        return BigReal(res);
    }
}

ostream &operator<<(ostream &out, const BigReal num)
{
    // TODO: insert return statement here
    out << num.sign << num.integer << '.' << num.fraction;
    return out;
}
