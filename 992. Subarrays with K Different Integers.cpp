// TC-> O(N)
// sc-> O(N)
class Solution {
public:

    int AtMostK(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;
        int count=0;
        int left=0,right=0;

        while (right<nums.size())
        {
            mp[nums[right]]++;
            while (mp.size()>k)
            {
                if (--mp[nums[left]]==0) 
                {
                    mp.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }

    int onepass(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;
        int count=0,left=0,left_big=0,right=0;
        while (right<nums.size())
        {
            mp[nums[right]]++;
            while (mp.size()>k)
            {
                mp[nums[left]]--;
                if (mp[nums[left]]==0) mp.erase(nums[left]);
                left++; 
                left_big=left;
            }
            while (mp[nums[left]]>1)
            {
                mp[nums[left]]--;
                left++;
            }
            if (mp.size()==k) count+=(1+left-left_big);
            right++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //return AtMostK(nums,k)-AtMostK(nums,k-1);
        return onepass(nums,k);
    }
};
