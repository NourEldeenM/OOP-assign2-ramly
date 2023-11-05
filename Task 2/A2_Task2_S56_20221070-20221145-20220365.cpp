// File: A2_Task2_S56_20221070-20221145-20220365.cpp
// Purpose: main file for Assignment2 Task2
// Author: Sara Mohamed Zaghloul / Maryam Omar / Nour Eldeen Mohamed
// Section: S5/6
// ID: 20221070 - 20220365 - 20221145
// TA: Eng. Maya / Eng. Nardeen
// Date: 23 Oct 2023
#include "bigreal.cpp"
#include <bits/stdc++.h>

using namespace std;

// Extra functions
void comparison();
void AddBignumbers();


int main()
{
    // BigReal b1("0.12345");
    // b1.print();
    // BigReal b2("-12345.678");
    // b2.print();
    // BigReal b3(".1234");
    // b3.print();
    // BigReal b4("+-1234");
    // b4.print();
    // BigReal b5("1...3+2-5");
    // b5.print();

    // BigReal b6;
    // b6.setNumber("-0000007000000.987650000000000");
    // cout << "B6 has sign: " << b6.getSign() << endl;
    // cout << "B6 has " << b6.getSize() << " digits" << endl;
    // b6.print();
    // b6.setNumber("-000.6789000");
    // b6.print();

    // BigReal b1("123.1");
    // BigReal b2("111.9");
    // BigReal b3;
    // b3 = b1 + b2;
    // b3.print();
    // if (b1 == b2)
    //     cout << "Yes\n";
    // else
    //     cout << "No\n";

    // BigReal b4 = b2;
    // cout << b4 << endl;

    // comparison();
    // AddBignumbers();
}



//----------------------------------------


void comparison()
{
    cout << "Enter the first number : ";
    string s;
    cin >> s;
    BigReal bg(s);
    BigReal bg2;
    cout << "Enter the second number : ";
    string t;
    cin >> t;
    bg2.setNumber(t);
    if (bg > bg2)
        cout << "The first big real number is greater than the second one \n";
    else if (bg < bg2)
        cout << "The first big real number is smaller than the second one \n";
    else
        cout << "Two numbers are equal\n";
}

void AddBignumbers()
{
    cout << "Enter the first number : ";
    string s;
    cin >> s;
    BigReal bg(s);
    BigReal bg2;
    cout << "Enter the second number : ";
    string t;
    cin >> t;
    bg2.setNumber(t);
    BigReal bg3;
    bg3 = bg + bg2;
    cout << "The result of the addition is : ";
    bg3.print();
}
