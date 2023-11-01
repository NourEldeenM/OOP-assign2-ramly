// File: A2_S6_20220365_4.cpp
// Purpose: Answer question 4 in Assignment 2
// Author: Nour Eldeen Mohamed
// Section: S6
// ID: 20220365
// TA: Eng. Maya
// Date: 26 Oct 2023

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <set>
// #include <bits/stdc++.h>

using namespace std;

// isPrime: Checks if a number is prime or not.
// int n: the number that will be checked.
bool isPrime(int n);

int main()
{
    // Taking N as input then filling
    // the array from 2 to N.
    int N;
    cin >> N;
    int arr[N - 1];
    for (int i = 0; i < N - 1; i++)
        arr[i] = i + 2;

    // Vector to store all primes.
    // Set to store all numbers that have been processed.
    vector<int> primes;
    set<int> st;
    int currentPrime;

    for (int i = 0; i < N - 1; i++)
    {
        // If the current item has not been processed and is prime:
        // 1. push it in primes,
        // 2. insert it in the set
        // 3. put any number that is divisible by this prime number
        //    into the set.
        if (st.find(arr[i]) == st.end() and isPrime(arr[i]))
        {
            currentPrime = arr[i];
            primes.push_back(arr[i]);
            st.insert(arr[i]);
            for (int j = i + 1; j < N - 1; j++)
            {
                if (st.find(arr[j]) == st.end() and arr[j] % currentPrime == 0)
                    st.insert(arr[j]);
            }
        }
    }

    // Print result
    cout << "Result:\n";
    for (auto &i : primes)
        cout << i << " ";
    cout << endl;
}

// Definition of isPrime.
bool isPrime(int n)
{
    for (int i = 2; i < (n / 2) + 1; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}