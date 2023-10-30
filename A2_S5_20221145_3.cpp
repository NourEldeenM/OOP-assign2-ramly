// File: A2_S5_20221145_3.cpp
// Purpose: quesion 3 assignment 2 
// Author: Maryam Omar Ahmed
// Section: S5
// ID: 20221145
// TA: ENG/ Maya
// Date: 27 Oct 2023


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string target, string delimiter);
int main(){
    vector<string>v ;
    v=split("1,2,3", ",");
    for(auto a:v)
cout << '"' <<a << '"' <<" ";
}
vector<string> split(string target, string delimiter){
    vector<string> res ; //vector to store in it;
while( target.size() ){
             int indx = target.find(delimiter); //index at which is delimiter;
                if(indx!=string::npos){ //compare each element with delimiter and do the condition if the element is the delimiter ;
            res.push_back(target.substr(0,indx)); // put in the vector substring from index 0 to delimiter-1;
            target=target.substr(indx+delimiter.size());//string will be from index that after delimiter to the end ;
            if(target.size()==0){
                res.push_back(target);//when there is no delimiter size=0 then push it in res;
            }

        }
        else{
                res.push_back(target); // the last element because there is no delimiter after it;
              target="";
        }

}
    return res;
}//split
