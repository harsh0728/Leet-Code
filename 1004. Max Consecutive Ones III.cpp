// TC-> O(N)
// SC-> O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,res=0,zeros=0;
        while (right<nums.size())
        {
            if (nums[right]==0) zeros++;
            if (zeros>k)
            {
                if (nums[left]==0) zeros--;
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};
