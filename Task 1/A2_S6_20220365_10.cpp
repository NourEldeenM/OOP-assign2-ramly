// File: A2_S6_20220365_10.cpp
// Purpose: Answer question 10 in Assignment 2
// Author: Nour Eldeen Mohamed
// Section: S6
// ID: 20220365
// TA: Eng. Maya / Eng. Nardeen
// Date: 29 Oct 2023

// Please make sure you downloaded words.h before
// attempting to run the code.
#include <iostream>
#include <string>
#include <fstream>
#include "words.h"

using namespace std;

int main()
{
    // Opening input file and making sure that
    // it exists
    string inName, outName;
    cout << "Enter input file name: ";
    cin >> inName; 
    ifstream file(inName);
    if (!file.is_open()){
        cout << "Error! Input file \"" << inName << "\" not found\n";
        return 0;
    }

    // Opening output file and making sure that
    // it exists
    cout << "Enter output file name: ";
    cin >> outName;
    ofstream out(outName);
    if (!file.is_open()) {
        cout << "Error! Output file \"" << outName << "\" not found\n";
        return 0;
    }

    // Looping through each word in
    // the input file.
    string word;
    while (file >> word) {

        // Search for the key word, if found in map,
        // replace it with its value.
        // else put the original word itself.
        if (mp.find(word) != mp.end())
            out << mp[word] << " ";
        else
            out << word << " ";
    }

    // close files
    file.close();
    out.close();
}