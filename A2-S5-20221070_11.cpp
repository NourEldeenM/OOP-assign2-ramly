// File: A2_S6_20220365_2.cpp
// Purpose: Answer question 2 in Assignment 2
// Author: Sara Mohamed Zaghloul
// Section: S5
// ID: 20221070
// TA: Eng. Maya
// Date: 28 Oct 2023


#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main() {
    fstream File_1,File_2;
    cout<<"Please Enter two files to compare\n";
    cout<<"Enter the first target file name :";
    // taking the name of two files in the computer
    // we should put the directory ".txt" when we input the names
    string File_name1; cin>>File_name1;
    File_1.open(File_name1);
    // check if the file is open or not
    if (File_1.is_open())
        cout<<"YES, the file is open you can do what you need\n";
    cout<<"Enter the second target file name :";
    string File_name2; cin>>File_name2;
    File_2.open(File_name2);
    if (File_2.is_open())
        cout<<"YES, the file is open you can do what you need\n";
    cout<<"Do you want a character by character comparison(a) or word by word (b) :";
    char target; cin>>target;
    bool flag=true, If_greater=false;
    string line1,line2;
    int num=1;
    if (target=='a'){
        // do a loop to check line by line so it will check every character in the two files 
        while (File_1.good()|| File_2.good()){
            getline(File_1,line1);
            getline(File_2,line2);
            // A code to check if any file end and the other file still have data 
            if (File_1.eof()|| File_2.eof()){
                if (!File_1.eof()&& File_2.eof()){
                     cout<<" We find a difference as the first file has number of characeters greater than the other one so the files are not identical\n";
                    cout<<"This defference appear in line number "<< num<< "\n ";
                    
                    If_greater=true;
                    break;
                }
                else if (!File_2.eof() && File_1.eof()) {
                    cout<<" We find a difference as the second file has number of characeters greater than the other one so the files are not identical\n";
                    cout<<"This defference appear in line number "<< num<< "\n ";
                    
                    If_greater=true;
                    break;
                }
            }
            // if we have a line not equal the other line he will print on the screen the 2 lines and their numbers 
            if (line1!=line2){
                cout<<"We find a difference at the line  number : ";
                cout<<num<<endl;
                cout<< " and there lines are : ";
                cout<< " file1 :"<<line1<<endl<<"file2 : "<< line2<<endl;
                flag=false;
            }
            num++;
            if (!flag)
                break;
        }
        //  A code if the 2 files are identical and their sizes are similar 
        if (flag && (!If_greater))
            cout<<"The files are identical\n";
        File_1.close();
        File_2.close();

    }
   // the option that compare word by word
    else {
        // this code will tell me the line that different
        while (File_1.good()||File_2.good()){
            getline(File_1,line1);
            getline(File_2,line2);
            if (line1!=line2){
                break;
            }
            num++;
        }
        File_1.seekg(0);
        File_2.seekg(0);
        string word1 ,word2;
        //loop and compare word by word
        while (File_1>>word1 || File_2>>word2){
            // if we have a file that has number of words greater than the other one 
            if (File_1.eof()|| File_2.eof()){
                if (!File_1.eof()&& File_2.eof()){
                    cout<<" We find a difference as the first file  has number of words greater than the other one so the files are not identical\n";
                    cout<<"This defference appear in line number "<< num<< "\n ";
                    If_greater=true;
                    break;
                }
                else if (!File_2.eof() && File_1.eof()) {
                     cout<<" We find a difference as the second file has number of words greater than the other one so the files are not identical\n";
                    cout<<"This defference appear in line number "<< num<< "\n ";
                    If_greater=true;
                    break;
                }
            }
            // if we have two different words he will do this conditions and break from the loop
            if (word1!=word2){
                flag=false;
                cout<<"We have a difference and files are not identical in this words :\n";
                cout<<"file 1: "<<word1<<"\nfile2 : "<<word2<<endl;
                cout<<"And this difference is in the line : "<<num;
                break;

            }
            
        }
        if (flag && (!If_greater))
            cout<<"Files are identical \n";
        File_1.close();
        File_2.close();

    }


}
