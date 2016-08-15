
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

  string reverseString(string s) {
      /* //methods one:Using STL reverse
        vector<char> str;
        for(int i=0;i<s.length();i++)
            str.push_back(s[i]);
        reverse(str.begin(),str.end());
        for(int i=0;i<s.length();i++){
            s[i]=str[i];
        }
       */

       int i=0;
       int j=s.length()-1;
       while(i<j){
          // cout<<s[i]<<" "<<s[j]<<endl;
           swap(s[i],s[j]);
         //  cout<<s[i]<<" "<<s[j]<<endl;
           i++;
           j--;
       }
        return s;
        
    }
     
int main()
{
    string s="hello";
    string result=reverseString(s);
    cout<<result<<endl;
    return 0;
}