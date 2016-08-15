

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct CompareFunc{
    bool operator()(const pair<int,int>& left,const pair<int,int>& right){
        return left.second>right.second;
    }
}compareFunc;

vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> order;
        sort(nums.begin(),nums.end());// O(nlogn)

        for(int i=0;i<nums.size();i++){
            if(order.find(nums[i])==order.end()){
                order[nums[i]]=1;
            }else{
                order[nums[i]]+=1;
            }
        }
        // for(map<int,int>::iterator iter=order.begin();iter!=order.end();iter++){
        //     cout<<iter->first<<":"<<iter->second<<endl;
        // }
        vector<pair<int,int>> vec(order.begin(),order.end());
        sort(vec.begin(),vec.end(),compareFunc);
        vector<pair<int,int>>::iterator iter = vec.begin();
       for(int i=0;i<k;i++){
        //    if(iter->second >=k){
                result.push_back(iter->first);
                iter++;
            }
        //    cout<<iter->first<<":"<<iter->second<<endl;
        


        return result; 

    }

int main(){
    vector<int> nums={1,2};//{1,1,1,2,2,2,2,3,3,3,3,3,3};
    // vector<int> tmp(nums.begin(),nums.end());
    // tmp.pop_back();
    // for(vector<int>::iterator iter=tmp.begin();iter!=tmp.end();iter++){
    //     cout<<*iter<<endl;
    // }
    vector<int> result;
    result= topKFrequent(nums,2);
    
    for(int i=0;i<result.size();i++){
        cout<<"result:"<<result[i]<<endl;
    }

    return 0;
}