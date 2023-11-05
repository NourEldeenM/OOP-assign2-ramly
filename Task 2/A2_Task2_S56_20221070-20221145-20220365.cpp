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

    // Test 1: default constructor & print
    // BigReal b1;
    // b1.print();

    // Test 2: parameterized constructor
    // BigReal b2("123.456");
    // b2.print();

    // Test 3: copy constructor & assignment operator
    // BigReal temp("13.98");
    // BigReal b3(temp);
    // b3.print();
    // BigReal x = b3;
    // x.print();

    // Test 4: Functions (getSize/getSign/setNumber)
    // BigReal b4;
    // b4.setNumber("-111157.83722");
    // cout << "Sign of b4 = " << b4.getSign() << endl;
    // cout << "Size of b4 = " << b4.getSize() << endl;

    // Test 5: Operator (> / < / ==)
    // BigReal b5("123"), b6("999"), b7("123");
    // if (b5 < b6)
    //     cout << "Yes1" << endl;
    // if (b6 > b7)
    //     cout << "Yes2" << endl;
    // if (b5 == b7)
    //     cout << "Yes3" << endl;

    // Test 6: Operator (+ / - / <<)
    // BigReal b8("111"), b9("888");
    // cout << b8 + b9 << endl;
    // cout << b8 - b9 << endl;

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
