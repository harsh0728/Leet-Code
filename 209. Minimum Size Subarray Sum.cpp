// Variable-size Sliding Window
// T.C-> O(N)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        // while (r < n) {
        //     sum += nums[r++];
        //     while (sum >= s) {
        //         len = min(len, r - l);
        //         sum -= nums[l++];
        //     }
        // }
        // return len == INT_MAX ? 0 : len;

        int left=0,sum=0,minLen=INT_MAX;
        for (int right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            while (sum>=s)
            {
                minLen=min(minLen,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return minLen==INT_MAX?0:minLen;
    }
};