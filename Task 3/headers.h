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

// Machine:
// loadProgramFile()
// outputState()
// Has a CPU
// Has a Memory
class Machine {
    CPU cpu
    Memory memory;
public:
    Machine() : CPU(memory) {}
    void loadProgramFile();
    void outputStateMemory();
    void outputStateRegisters();


};


// Cpu:
// int programCounter
// int instructionRegister
// runProgram()
// fetch()
// decode()
// execute()
class CPU {
private:
    int programCounter = 0;
    string instruction = "";
    int registers[16] = {0};
    const Memory& memory;
public:
    // void runProgram();
    CPU(memory) : Memory(memory) {}
    bool fetch();
    void execute();
    int read(int address);

};

// Memory:
// memory
// size
// void store(int address, int value)
// int read(int address)
class Memory {
    vector<string> m;
public:
    void store(int address, string value);
    string read(int address);
    int size = m.size();
};


// Fetch: take data from memory where the counter points and put it in instruction register
// Decode: 




// Machine: class
// CPU: class
// Memory: class
// Register: class
// Instruction

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
