#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "headers.cpp"
using namespace std;

int main()
{
    Machine m1;
    m1.loadProgramFile();

    cout << "Display memory? Y/N: ";
    char x;
    cin >> x;
    if (x == 'Y')
        m1.outputStateMemory();

    cout << "Display registers? Y/N: ";
    cin >> x;
    if (x == 'Y')
        m1.outputStateRegisters();
    while (true)
    {
        if (m1.fetch() == true)
            m1.fetch();
        else
            return false;
        
        if (m1.execute() != false)
            m1.execute();
        else
            break;
    }
    cout << "Program Done!\n";
    cout << "Display registers? Y/N: ";
    cin >> x;
    if (x == 'Y')
        m1.outputStateRegisters();
}
