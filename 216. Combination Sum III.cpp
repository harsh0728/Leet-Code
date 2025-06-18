class Solution {
public:

    void backtrack(int k,int tar, int start,vector<int>& sum,vector<vector<int>>& res)
    {
        if (tar==0 && sum.size()==k)
        {
            res.push_back(sum);
            return;
        }

        for (int i=start;i<=9;i++)
        {
            if (i>tar) break;
            sum.push_back(i);
            backtrack(k,tar-i,i+1,sum,res);
            sum.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sum;
        backtrack(k,n,1,sum,res);
        return res;
    }
};