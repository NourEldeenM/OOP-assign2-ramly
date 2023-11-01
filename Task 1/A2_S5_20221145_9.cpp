// File: A2_S5_20221145_9.cpp
// Purpose: quesion 9 assignment 2
// Author: Maryam Omar Ahmed
// Section: S5
// ID: 20221145
// TA: ENG/ Maya
// Date: 30 Oct 2023

#include <bits/stdc++.h>
using namespace std;

bool bears(int n ){
  if (n==42){
        return true ;
    }// base case

if (n%2==0 && bears(n/2)){
    return true ;
}

if(n%3==0 or n%4==0 && (n % 10!=0) && (( (n % 100) / 10 )!=0) &&bears(n-((n % 10) * ((n % 100) / 10)))){
return true;
}

if(n%5==0 && bears(n-42)){
    return true ;
}

}
int main() {
    cout << "enter number of bears:"<<endl;
    int num ; cin >>num ;
    if(bears(num)){
        cout << "bears("<<num << ") is true"<<endl;
    }
    else{
        cout << "bears("<<num << ") is false"<<endl;
    }
}
