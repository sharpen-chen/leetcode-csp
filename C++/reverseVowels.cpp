
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


 bool CotainVowels(char ch){
     ch=tolower(ch);
     if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
    else
        return false;
 }   

 string reverseVowels(string s) {
       vector<char> vowels;
       for(int i=0;i<s.length();i++)
           if(CotainVowels(s[i]))
               vowels.push_back(s[i]);           
       
        for(int i=0;i<s.length();i++)
            if(CotainVowels(s[i])){
                s[i]=vowels.back();
                vowels.pop_back();
            }
                
            
        
    //    for(int i=0;i<vowels.size();i++)
    //    cout<<vowels[i]<<endl;
        return s;
    }
  

int main()
{
    string s="aA";
    string result=reverseVowels(s);
    for(int i=0;i<result.length();i++)
       cout<<result[i]<<endl;
    return 0;
}