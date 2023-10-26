#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    string m="",t="";
    for (int i=0;i<s.size();i++){
        t+=s[i];
        // check all the words in the string
        if (s[i]==' '){
        // check if we have a Masculine pronoun by using the function "find" and check if he is a masculine pronouns or any word which have the characters of any masculine pronoun
            
            if (t=="He"){
           size_t found = t.find("He");
           if (found==0){
              
              found+=2;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or she");
           }
              m+=t;
            }

            else if (t.find("he")!=std::string::npos){
             size_t found = t.find("he");
             if (found==0){
             found+=2;
             if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or she");
             }
              m+=t;

            }
            // check if the word has the word himself or not
            else if (t.find("himself")!=std::string::npos){
             size_t found = t.find("himself");
             if (found==0){
                
              found+=7;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or herself");
             }
              m+=t;
            }
            else if (t.find("Himself")!=std::string::npos){
              size_t found = t.find("Himself");
              if (found ==0){
                  
               found+=7;
               if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or herself");
              }
              m+=t;
            }
            else if (t.find("Him")!=std::string::npos){
             size_t found = t.find("Him");
             if (found ==0){
             found+=3;
             if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;

            }
            else if (t.find("him")!=std::string::npos){
             size_t found = t.find("him");
             if (found ==0){
              found+=3;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;
            }
            else if (t.find("His")!=std::string::npos){
             size_t found = t.find("His");
             if (found ==0){
              found+=3;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;
            }
            else if (t.find("his")!=std::string::npos){
             size_t found = t.find("his");
             if (found==0){
              found+=3;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;
            }
            else {
                m+=t;
            }
            t="";
        }
        // check the last word in the string 
         else if (i==s.size()-1){
       if (t=="He"){
           size_t found = t.find("He");
           if (found==0){
              found+=2;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or she");
           }
              m+=t;
            }

            else if (t.find("he")!=std::string::npos){
             size_t found = t.find("he");
             if (found==0){
             found+=2;
             if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or she");
             }
              m+=t;

            }
            else if (t.find("himself")!=std::string::npos){
             size_t found = t.find("himself");
             if (found==0){
              found+=7;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or herself");
             }
              m+=t;
            }
            else if (t.find("Himself")!=std::string::npos){
              size_t found = t.find("Himself");
              if (found ==0){
               found+=7;
               if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or herself");
              }
              m+=t;
            }
            else if (t.find("Him")!=std::string::npos){
             size_t found = t.find("Him");
             if (found ==0){
             found+=3;
             if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;

            }
            else if (t.find("him")!=std::string::npos){
             size_t found = t.find("him");
             if (found ==0){
              found+=3;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;
            }
            else if (t.find("His")!=std::string::npos){
             size_t found = t.find("His");
             if (found ==0){
              found+=3;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;
            }
            else if (t.find("his")!=std::string::npos){
             size_t found = t.find("his");
             if (found==0){
              found+=3;
              if (!(isalpha(t[found])) && !(isdigit(t[found])))
              t.insert(found," or her");
             }
              m+=t;
            }
            else {
                m+=t;
            }
            t="";
    }
    }
    cout<<m;
}
