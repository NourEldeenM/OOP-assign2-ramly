// File: A2_S6_20220365_5.cpp
// Purpose: Answer question 5 in Assignment 2
// Author: Sara Mohamed Zaghloul
// Section: S5
// ID: 20221070
// TA: Eng. Maya
// Date: 30 Oct 2023



#include<bits/stdc++.h>

using namespace std;

void pattern(int n, int i){
    if (n==0)
      return;
      //Base case
    pattern (n/2,i);
    // The first recursive funcation
        for (int k=0;k<i;k++)
        cout<<' ';
        // A loop to put a spaces depends on the value of (i)
        for (int k=0;k<n;k++)
        cout<<"*  ";
        //put the astrisks in their places
        cout<<endl;
    pattern (n/2,i+=n/2);
    // The second recursive funcation
    
}


int main() {
    cout<<"Enter the number of maximum astrisks do you want (your number is a power of 2 greater than zero) : ";
    int r; cin>>r;
    cout<<"Enter the coloumn that you want to start in :";
    int c; cin>>c;
    // Taking the arguments
    pattern(r,c);
    // Call the function
}
