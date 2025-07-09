// T.C-> O(N)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        int sum=0,maxSum=INT_MIN;

        for (int i=0;i<k;i++) 
        {
            sum+=nums[i];
        }
        maxSum=sum;

        for (int i=k;i<nums.size();i++)
        {
            sum+=nums[i]-nums[i-k];
            maxSum=max(sum,maxSum);
        }
        ans=double(maxSum)/k;
        return ans;
    }
};