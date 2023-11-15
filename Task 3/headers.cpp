#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "headers.h"
using namespace std;

int hexToDecimal(std::string hexNumber)
{
    int decimalNumber = 0;
    int power = 0;

    // Iterate through each character of the hexadecimal number from right to left
    for (int i = hexNumber.size() - 1; i >= 0; i--)
    {
        char c = hexNumber[i];
        int digit;

        // Convert hexadecimal digit to decimal value
        if (c >= '0' && c <= '9')
        {
            digit = c - '0';
        }
        else if (c >= 'A' && c <= 'F')
        {
            digit = c - 'A' + 10;
        }
        else if (c >= 'a' && c <= 'f')
        {
            digit = c - 'a' + 10;
        }
        else
        {
            // Invalid character, handle error or return an appropriate value
            return -1;
        }

        // Add the decimal value of the digit to the final decimal number
        decimalNumber += digit * pow(16, power);
        power++;
    }

    return decimalNumber;
}

void Machine::loadProgramFile()
{
    // 1. Open file
    string fileName = "input.txt";
    ifstream inputFile(fileName);
    if (!inputFile.is_open())
        return;

    // 2. Read instructions from file
    string word;
    int line = 0;
    while (getline(inputFile, word))
    {
        // 3. Fill the memory array with the instructions
        if (line > 256)
        {
            cout << "Reached maximum limit in memory\n";
            break;
        }
        Memory.push_back(word.substr(0, 2));
        Memory.push_back(word.substr(2, 2));
        line += 2;
    }
}

void Machine::outputStateMemory()
{
    for (int i = 0; i < Memory.size(); i++)
        cout << i << "\t" << Memory[i] << endl;
    cout << "Counter at cell: " << programCounter << endl;
}

void Machine::outputStateRegisters()
{
    for (int i = 0; i < 16; i++){

            stringstream stream;
    stream << hex << registers[i];
    string hexString = stream.str();

        cout << i << "\t" << hexString << endl;
    }
}

bool Machine::fetch()
{
    if (programCounter >= Memory.size())
    {
        cout << "Counter reached the end of memory!\n";
        return false;
    }
    else
    {
        instruction = Memory[programCounter];
        instruction += Memory[programCounter + 1];
//        programCounter += 2;
        return true;
    }
}

bool Machine::execute()
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
        string s2 = Memory[decimal];
        int hexNumber1 = stoi(s2, nullptr, 16);

        registers[moveTo] = hexNumber1;
        programCounter+=1;
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

    // Put hexNumber into register of index moveTo
    registers[moveTo] = hexNumber;
    programCounter+=1;
}
    else if (instruction.front() == '3')
    {//from register to memory

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

        stringstream stream;
    stream << hex << vofR;
    string hexString = stream.str();

        Memory[decimal] = hexString;
        programCounter+=1;
    }
    else if (instruction.front() == '4')
    // 40A4 move content in register A to register 4
    {
        char move1 = instruction[2], move2 = instruction[3];
        int moveFrom, moveTo;
        if (mp.find(move1) != mp.end())
            moveFrom = mp[move1];
        else
            moveFrom = move1 - '0';

        if (mp.find(move2) != mp.end())
            moveTo = mp[move2];
        else
            moveTo = move2 - '0';

        registers[moveTo] = registers[moveFrom];
        programCounter+=1;
    }
        else if (instruction.front() == '5')
        {
            char For_sum = instruction[1], move1 = instruction[2], move2 = instruction[3];
            int moveto1, moveto2, moveto3;
            if (mp.find(move1) != mp.end())
                moveto1 = mp[move1];
            else
                moveto1 = move1 - '0';

            if (mp.find(move2) != mp.end())
                moveto2 = mp[move2];
            else
                moveto2 = move2 - '0';
            if (mp.find(For_sum) != mp.end())
                moveto3 = mp[For_sum];
            else
                moveto3 = For_sum - '0';
            int addition = registers[moveto2] + registers[moveto1];
            registers[moveto3] = addition;
            programCounter+=1;
        }
    else if (instruction.front() == 'B')
    {
        char reg = instruction[1];
        int to_int;
        if (mp.find(reg) != mp.end())
            to_int = mp[reg];
        else
            to_int = reg - '0';
        if (registers[0] == registers[to_int])
        {
            int Target_add = stoi(instruction.substr(2, 2), nullptr, 16);
            if (Target_add <= Memory.size())
            {
                // bool counterJumped = true;
                programCounter = Target_add;
                //Check if the target address is before the current one or not
                // if ((programCounter - Target_add) < 0)
                // // counter = 2, target_add = 5
                //     programCounter -= programCounter - Target_add;
                // else
                //     programCounter += abs(programCounter - Target_add);
            }
        }
        programCounter+=1;
    }
    else if (instruction.front() == 'C')
    {
        return false;
    }
    else
    {
        cout << "Invalid instruction at line " << programCounter + 1 << endl;
        return false;
    }
    return true;
}
