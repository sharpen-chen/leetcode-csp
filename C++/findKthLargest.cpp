
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct CompareFunc{
//     bool operator()(const int & left,const int & right){
//         return left>right;
//     }
// }comp;
 int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());// STL supply 
        return nums[k-1];
    }

     
int main()
{
    vector<int> nums={3,2,1,5,9,4};
    cout<<findKthLargest(nums,2)<<endl;
    return 0;
}