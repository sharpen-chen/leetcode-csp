
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 int integerBreak(int n) {
        const int base=3;
     //   vector<int> result;
      //  int tmp=n;
        if(n==2)//||n==3)
            return 1;
        if(n==3)
            return 2;
        if(n==4)
            return 4;
        if(n>4){
            int part=integerBreak(n-base);
            return base*(n-base>part?n-base:part);
        }
    }

     
int main()
{
    int input=10;
    cin>>input;
    cout<<integerBreak(input)<<endl;
    return 0;
}