// File: A2_S6_20220365_7.cpp
// Purpose: Answer question 7 in Assignment 2
// Author: Nour Eldeen Mohamed
// Section: S6
// ID: 20220365
// TA: Eng. Maya
// Date: 26 Oct 2023

/*
You can use this as a test case:
1 4
2 6
4 4
6 1
4 3

output:
2 6
6 1
1 4
4 4
4 3
*/
#include <bits/stdc++.h>

using namespace std;

// Struct to store dominos data in it
struct Domino
{
    /* data */
    int leftDots;
    int rightDots;
};

// Bool function to check if we can form a sequence
// out of the Domino structs
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

    map<int, int>::iterator it;
    vector<int> oddNums;
    for (it = mp.begin(); it != mp.end(); it++)
    {
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

// Function that aranges the dominos in a deque so that
// we can print the sequence of the dominos
/* 
Steps:
1. Initialize an empty list
2. Choose any pair form the original set and add it to the new list
3. Look for a pair whose left side matches the right side, & vice versa.
4. If a matching pair is found, add it to the new list and update the left and right reference pairs.
5. Repeat steps 4 & 5 until size of dq equals 5
6. The new list will contain the arranged pairs, where left side equals the right side of the
   next pair.
*/
deque<Domino> displaySequence(vector<Domino> &v)
{
    deque<Domino> dq;
    dq.push_back(v[0]);
    int leftSide = v[0].leftDots;
    int rightSide = v[0].rightDots;
    while (dq.size() < 5)
    {
        for (int i = 1; i < 5; i++)
        {
            if (v[i].leftDots == rightSide)
            {
                dq.push_back(v[i]);
                rightSide = v[i].rightDots;
                v[i].leftDots = 0;
                v[i].rightDots = 0;
            }
            else if (v[i].rightDots == leftSide)
            {
                dq.push_front(v[i]);
                leftSide = v[i].leftDots;
                v[i].leftDots = 0;
                v[i].rightDots = 0;
            }
        }
    }
    return dq;
}


//main funciton
int main()
{
    vector<Domino> v;
    Domino x;
    // Taking input
    for (int i = 0; i < 5; i++)
    {
        printf("Enter left and right dots for domino number %d: \n", i + 1);
        cin >> x.leftDots >> x.rightDots;
        v.push_back(x);
    }

    if (FormsDominoChain(v))
    {
        // We can do a sequence
        // Make the sequence in dq
        deque<Domino> dq = displaySequence(v);
        // Printing the sequence
        for (int i = 0; i < 5; i++) {
            printf("%d|%d", dq[i].leftDots, dq[i].rightDots);
            if (i != 4)
                cout << " - ";
        }
        cout << "\n";
    }
    else
    {
        // We can't do a sequence
        cout << "We can't form a chain out of this sequence!\n";
    }
}
