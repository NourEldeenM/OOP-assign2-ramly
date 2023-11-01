// File: A2_S6_20220365_1.cpp
// Purpose: Answer question 1 in Assignment 2
// Author: Nour Eldeen Mohamed
// Section: S6
// ID: 20220365
// TA: Eng. Maya
// Date: 25 Oct 2023

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main()
{
    string input, output = "";
    // Take input
    getline(cin, input);
    // Pushing first letter to output in Uppercase
    output.push_back(toupper(input[0]));
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] == ' ' or input[i] == '\n')
        {
            // Add a space if you found a breakline or space character
            // then loop and skip any spaces and
            // breaklines until you find a letter.
            output += " ";
            while (true)
            {
                if (input[i + 1] == ' ' or input[i + 1] == '\n')
                    i++;
                else
                    break;
            }
        }
        else
        {
            // If the current ith char isn't " " nor "\n"
            // then add it to output in lowercase.
            output += tolower(input[i]);
        }
    }
    cout << "Result:\n"
         << output << endl;
}
