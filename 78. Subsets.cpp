class Solution {
public:

    void backtrack(vector<int>& nums,int start,vector<vector<int>>& res,vector<int>& curr)
    {
        res.push_back(curr);

        for (int i=start;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            backtrack(nums,i+1,res,curr);
            curr.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums,0,res,curr);
        return res;
    }
};