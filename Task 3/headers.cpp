#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "headers.h"
using namespace std;

void Machine::loadProgramFile()
{
    // 1. Open file
    string fileName = "input.txt";
    ifstream inputFile(fileName);
    if (!inputFile.is_open())
        return -1;

    // 2. Read instructions from file
    string word;
    int line = 1;
    while (getline(inputFile, word))
    {
        // 3. Fill the memory array with the instructions
        if (line > 256)
        {
            cout << "Reached maximum limit in memory\n";
            break;
        }
        this->memory.store(line - 1, word.substr(0, 2));
        this->memory.store(line, word.substr(2, 2));
        line++;
    }
}

void Machine::outputStateMemory()
{
    int sizeOfMemory = this->memory.size;
    for (int i = 0; i < sizeOfMemory; i++)
        cout << i << "\t" << this->memory.read(i) << endl;
}

void Machine::outputStateRegisters()
{
    int sizeOfRegister 15;
    for (int i = 0; i < 15; i++)
        cout << i << "\t" << this->cpu.read[i] << endl;
}

void Memory::store(int address, string value)
{
    this->m[address] = value;
}

string Memory::read(int address)
{
    return m[address];
}

bool CPU::fetch()
{
    if (programCounter >= memory.size)
    {
        cout << "Memory limit reached\n";
        return false;
    }
    instruction = memory.read(programCounter);
    instruction += memory.read(programCounter + 1);
    programCounter += 2;
    return true;
}

void CPU::execute()
{
    if (fetch())
    {
        if (instruction.front() == '1')
        {
            char move2 = instruction[1];
            int moveTo;
            if (mp.find(move2) != mp.end())
                moveTo = mp[move2];
            else
                moveTo = move2 - '0';

            // Converting string to hexnumber
            int hexNumber = stoi(instruction.substr(2, 2), nullptr, 16);
            string s1 = instruction.substr(2, 2);
            int decimal = hexToDecimal(s1);
            cout << "decimal : " << decimal << endl;
            // string s2 = Memory[decimal];
            string s2 = memory.read(decimal);

            int value = hexToDecimal(s2);
            registers[moveTo] = value;
        }
        else if (instruction.front() == '2')
        // 20A3 load A3 in register 0
        {
            char move2 = instruction[1];
            int moveTo;
            if (mp.find(move2) != mp.end())
                moveTo = mp[move2];
            else
                moveTo = move2 - '0';

            // Converting string to hexnumber
            int hexNumber = stoi(instruction.substr(2, 2), nullptr, 16);

            // Put hexnumber into register of index 0
            registers[moveTo] = hexNumber;
        }
        else if (instruction.front() == '3')
        {
            char move2 = instruction[1];
            int moveTo;
            if (mp.find(move2) != mp.end())
                moveTo = mp[move2];
            else
                moveTo = move2 - '0';
            int hexNumber = stoi(instruction.substr(2, 2), nullptr, 16);

            string s1 = instruction.substr(2, 2);
            int decimal = hexToDecimal(s1);
            int vofR = registers[moveTo];
            string s2 = to_string(vofR);
            // Memory[decimal] = s2;
            memory.store(decimal, s2);
        }
    }
}

int CPU::read(int address)
{
    return registers[address];
}
