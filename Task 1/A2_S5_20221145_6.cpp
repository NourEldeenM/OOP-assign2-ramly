// File: A2_S5_20221145_6.cpp
// Purpose: quesion 6 assignment 2 
// Author: Maryam Omar Ahmed
// Section: S5
// ID: 20221145
// TA: ENG/ Maya
// Date: 27 Oct 2023

#include <bits/stdc++.h>
using namespace std;

class invert_binary{

public:
     static binaryPrint(int n){

if(n ==0){
    return 0;
}
else{
    return n%2 + 10*(binaryPrint(n/2));//if n is even will return 0 and if it is odd return 1 and then divide the number by 2 to complete it
}
     }
};
//====================================================
class morenumbers{
public:
     static numbers(string prefix, int k){

     for(int i=0 ; i< k*k ; i++){ //k to power 2 is the number of possibles combinations
            cout<<prefix ;
        int possibles = i;

         invert_binary tobinary ; //declare variable to convert the number of possibles to binary

       int z = tobinary.binaryPrint(possibles);//store it in new variable

       std::string str = std::to_string(z);//convert the variable to string so we can compare its index with k
       if(str.size()<k){
       for(int i=0 ; i<k-1 ; i++)
       {
        cout<< '0'; //add zeros to make all possibles the same size
       }
       }
        cout << z <<endl; //binary

     }//for



     }//numbers

};




//=====================================================


int main (){
invert_binary num;
cout<<num.binaryPrint(27)<<endl;
morenumbers a ;
a.numbers("00101",2);
}

