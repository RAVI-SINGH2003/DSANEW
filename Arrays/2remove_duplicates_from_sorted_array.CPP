#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        
        int pos=1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            continue;
            else
            nums[pos++]=nums[i];
        }
        return pos;
 }
 int main()
 {
     vector<int> nums{0,0,1,1,2,2,3,3};
     cout<<removeDuplicates(nums);
 }