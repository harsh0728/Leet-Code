#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // most optimised approach O(N)

        int n=nums.size();
        vector<int> ans;

         unordered_map<int,int> m;
         for (int i=0;i<n;i++)
         {
             if (m.find(target-nums[i])!=m.end())
             {
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                return ans;
                // directly we return {m[target-nums[i]],i};
             }
             
                 m[nums[i]]=i;
             
         }
         return ans;
        
        
        
    
        
        
        
        
        // // Brute force approach O(n2)
        // int n=nums.size();
        // vector<int> ans;
        // for (int i=0;i<n;i++)
        // {
        //     for (int j=i+1;j<n;j++)
        //     {
        //         if (nums[i]+nums[j]==target)
        //         {
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             return ans;
        //         }
        //     }
        // }
        // return ans;
        
    }
};