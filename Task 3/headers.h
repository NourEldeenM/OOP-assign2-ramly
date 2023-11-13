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
    {'F', 15},

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
    bool fetch();
    bool execute();
};
