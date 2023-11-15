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
    while (true)
    {
        cout << "Display Menu? Y/N: ";
        char x; cin >> x;
        if (x == 'Y')
            m1.displayMenu();
        if (m1.fetch() == true)
            m1.fetch();
        else
            break;
        
        if (m1.execute() == true)
            m1.execute();
        else
            break;
    }
    cout << "Program Done!\n";
}
