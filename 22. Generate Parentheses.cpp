class Solution {
public:

    void backtrack(int n,int m,vector<string>& res, string curr)
    {
        if (n==0 && m==0)
        {
            res.push_back(curr);
            return;
        }

        if (m>0) backtrack(n,m-1,res,curr+")");
        if (n>0) backtrack(n-1,m+1,res,curr+"(");


    }

    void Backtrack(vector<string>& res, string current, int open, int close, int n) {
    if (current.length() == 2 * n) {
        res.push_back(current);
        return;
    }

    if (open < n) {
        Backtrack(res, current + '(', open + 1, close, n);
    }

    if (close < open) {
        Backtrack(res, current + ')', open, close + 1, n);
    }
}

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        //backtrack(n,0,res,curr);  // 1st method
        Backtrack(res, "", 0, 0, n);  // 2nd method

        return res;
       
    }
};