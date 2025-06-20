class Solution {
public:

    void backtrack(int n,int k,int start,vector<vector<int>>& res,vector<int>& arr)
    {
        if (arr.size()==k)
        {
            res.push_back(arr);
            return;
        }

        for (int i=start;i<=n;i++)
        {
            arr.push_back(i);
            backtrack(n,k,i+1,res,arr);
            arr.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr;
        backtrack(n,k,1,res,arr);
        return res;
    }
};