// File: A2_S5_20221145_3.cpp
// Purpose: quesion 12 assignment 2 
// Author: Maryam Omar Ahmed
// Section: S5
// ID: 20221145
// TA: ENG/ Maya
// Date: 27 Oct 2023

#include <bits/stdc++.h>
using namespace std;


int main(){
    cout<< "enter the target file:"<<endl;
    string filename ;
    cin>>filename;


ifstream file(filename); //declare input;

map<string,int>wordpoints=//keywords and their points
{
    {"FACC",3} ,{"Crelan Bank",3} ,{"Sony Pictures",3} ,{"Facebook",1} ,{"Google",2} ,{"Colonial Pipeline",3} ,
    {"Imitating legitimate business activities",2} ,{"Creating a sense of urgency",2} ,{"Prompting the recipient to act",1} ,{"Message From ####",3} ,
    {"You have a New Message",1} ,{"Telephone Message for ####",1} ,{"You have a New Message",1} ,{"Telephone Message for ####",1} ,
    {"Verification Required!",2} ,{"Action Required: Expiration Notice on [business email address]",3}
    ,{"[Action Required] Password Expire",3} ,{"Attention Required. Support ID: ####",3} ,{"You have a Google Drive File Shared",2}
    ,{"[Name] sent you some files",2} ,
    {"File- ####",1} ,{"[Business Name] Sales Project Files and Request for Quote",3} ,{"File Document ####",1}
     ,{"[Name], You have received a new document in [Company system]",2}
     ,{"Attn: [Name] – You have an important [Business name] designated Document",3} ,{"Document For [business email address]",2}
     ,{"View Attached Documents",1} ,{"[Name] shared a document with you",1} ,{"Verification Required!",3}
     ,{"eFax® message from “[phone number]” – 2 page(s), Caller-ID: +[phone number]",3}

};
int total=0; //variable to store the total points in the text;
map<string , int > wordcnt;//map to store keywords and total points for each word or phrase;

string line;
while (std::getline(file, line))  { //to read the text line by line not word;
for (const auto& a : wordpoints) { //iterator for the first map by reference
             string keyword = a.first;
            int points = a.second;
            size_t pos = line.find(keyword);//search for the first keyword in the line;
            while (pos != std::string::npos) {//meaning while it is a valid position;
                wordcnt[keyword]++;//to increase the count of each keyword
                total += points;//sum of all points
                pos = line.find(keyword, pos + keyword.length());
                //searches for substring of the keyword in the line
                // start from the position after the previous keyword;
            }
}
}
file.close();

for (const auto& a : wordcnt) { //iterator for the second map which has keywords and how many times for each one
               int times = a.second;//number of appearence
  string keyword = a.first;
        int points = wordpoints[keyword] * times; //to get total point for each keyword

        cout <<"keyword : "<<keyword <<endl;
       cout <<"times : "<<times<<endl;
      cout << "points "<<points <<endl;



}
 cout << "totalpoints : "<<total;
}




