// File: A2_S6_20220365_7.cpp
// Purpose: Answer question 7 in Assignment 2
// Author: Nour Eldeen Mohamed
// Section: S6
// ID: 20220365
// TA: Eng. Maya
// Date: 26 Oct 2023

#include <bits/stdc++.h>

using namespace std;

struct Domino
{
    /* data */
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<Domino> &v)
{
    map<int, int> mp;
    int totalSum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i].rightDots]++;
        mp[v[i].leftDots]++;
        totalSum += v[i].rightDots;
        totalSum += (-1 * v[i].leftDots);
    }

    map<int,int>::iterator it;
    vector<int> oddNums;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second % 2 != 0)
            oddNums.push_back(it->first);
    }

    if (oddNums.size() == 2 or oddNums.size() == 0)
    {
        if (oddNums.size() == 2)
        {
            int x = abs(oddNums[0] - oddNums[1]);
            if (x == totalSum)
                return true;
            else
                return false;
        }
        return true;
    }
    else
        return false;
    

}

void displaySequence(vector<Domino> &v) {

}

int main() {

    vector<Domino> v;
    Domino x;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter left and right dots for domino number %d: \n", i + 1);
        cin >> x.leftDots >> x.rightDots;
        v.push_back(x);
    }

    if (FormsDominoChain(v))
    {
        // We can do a chain
        cout << 1 << endl;
    }
    else {
        // We can't do 
        cout << "We can't form a chain out of this sequence!\n";
    }
}
