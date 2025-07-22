// TC-> O(N)
class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int res = 0, left = 0, odd_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 != 0) odd_count++;

            while (odd_count > k) {
                if (nums[left] % 2 != 0) odd_count--;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
