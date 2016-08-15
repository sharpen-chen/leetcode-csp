#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int index=0;
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            if(i>0 && nums1[i]==nums1[i-1]){
                continue;
            }
            // can improve velocity here. using index instead of loop
            // for(int j=0 ;j<nums2.size();j++){
            //     if(j>0 && nums2[j]==nums2[j-1]){
            //         continue;
            //     }
            //     if(nums1[i]==nums2[j]){
            //         result.push_back(nums1[i]);
            //     }
            // }
           // cout<<nums1[i]<<endl;
            while(index<nums2.size() && nums1[i]>nums2[index]){
                index++;
                }; // move index to the first equal value, there are two possible result: inner and bound.
            if(index<nums2.size() ){
                if(nums1[i]==nums2[index])
                   result.push_back(nums1[i]);
            }
            if(index==nums2.size()){
                break;
            }
            

        }
        return  result;
    }
 
int main()
{
    vector<int> nums1={1,2};//{1,1,3,4,2,2};
    vector<int> nums2={1,1};//{6,2,1,2,1};
    vector<int> result= intersection(nums1,nums2);
//     for(vector<int>::iterator ite = vec.begin();ite!=vec.end();ite++)//做遍历打印
// cout<<*ite<<" ";
// cout<<endl;
    for(int i=0;i<result.size();i++){
        cout<<"result:"<<result[i]<<endl;
    }

   return 0;
}


