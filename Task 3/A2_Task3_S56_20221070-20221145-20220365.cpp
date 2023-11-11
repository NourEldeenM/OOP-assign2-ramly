// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int hexToDecimal(std::string hexNumber) {
    int decimalNumber = 0;
    int power = 0;

    // Iterate through each character of the hexadecimal number from right to left
    for (int i = hexNumber.size()-1; i >= 0; i--) {
        char c = hexNumber[i];
        int digit;

        // Convert hexadecimal digit to decimal value
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else {
            // Invalid character, handle error or return an appropriate value
            return -1;
        }

        // Add the decimal value of the digit to the final decimal number
        decimalNumber += digit * pow(16, power);
        power++;
    }

    return decimalNumber;
}


vector<string> Memory;
int programCounter;
int registers[16] = {0};
map<char, int> mp = {
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},

};

int main()
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
        Memory.push_back(word);
        line++;
    }

    // 4. Make the pointer point to first cell in the memory
    programCounter = 0;
    while (programCounter != Memory.size())
    {
        bool counterJumped = false;
        // 5. Display memory if wanted
        cout << "Display Memory? Y/N: ";
        char x;
        cin >> x;
        if (x == 'Y')
        {
            for (int i = 0; i < Memory.size(); i++)
                cout << i << '\t' << Memory[i] << endl;
            cout << "Program Counter at line " << programCounter << endl;
        }


        // 6. Take the instruction
        string instruction = Memory[programCounter];

        // 7. Do the instruction
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
            cout<<"decimal : "<<decimal<<endl;
           string s2= Memory[decimal];

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
        // else if (instruction.front() == '3')
        // {

        // }
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
        }
        // else if (instruction.front() == '5')
        // {

        // }
        // else if (instruction.front() == '6')
        // {

        // }
        else if (instruction.front() == 'B')
        {
            counterJumped = true;

        }
        // else if (instruction.front() == 'C')
        // {

        // }
        else
        {
            cout << "Invalid instruction at line " << programCounter + 1 << endl;
        }

        // 5. Display registers if wanted
        cout << "Display Registers? Y/N: ";
        cin >> x;
        if (x == 'Y')
        {
            for (int i = 0; i < 16; i++)
                cout << i << '\t' << registers[i] << endl;
        }

        // 9. Increase counter by 1
        if (!counterJumped)
            programCounter++;
    }
}
