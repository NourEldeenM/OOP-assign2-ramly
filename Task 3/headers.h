#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

map<char, int> mp = {
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15}
};

class Machine {
    vector<string> Memory;
    int programCounter = 0;
    int registers[16] = {0};
    string instruction;
public:
    void loadProgramFile();
    void outputStateMemory();
    void outputStateRegisters();
    void displayMenu();
    bool fetch();
    bool execute();
    void runProgram();
};


/*
Description for instructions in input.txt to 
test the program:

1. 200A -> Load register 0 with 0A
2. 210A -> Load register 1 with 0A
3. B108 -> If register1 = register0 then go to cell 08 in memory
4. C000 -> If the above condition is false, then close the program
5. 25FF -> Load register 5 with FF
6. 5801 -> Add register0 and register1, then store in register 8
7. 405A -> Move pattern in register 5 to register A
8. 1F00 -> Load register F with pattern in memory cell 00
9. 3519 -> Store in memory cell of address 19(hex) or (25)decimal the pattern
           found in register 5
10.C000 -> End the programs
*/
