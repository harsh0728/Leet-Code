class Solution {
public:

    int n;
    set<vector<int>> s;

    void CombSum(vector<int>& candidates,int i,vector<int>& comb,vector<vector<int>>& res, int target)
    {
        if (i==n || target<0) return;
        if (target==0)
        {
            if (s.find(comb)==s.end())
            {
                res.push_back(comb);
                s.insert(comb);
            }
            
            return;
        }

        comb.push_back(candidates[i]);
        // include single time
        CombSum(candidates,i+1,comb,res,target-candidates[i]);
        // include multiple times
        CombSum(candidates,i,comb,res,target-candidates[i]); 
        comb.pop_back(); 
        // exclude
        CombSum(candidates,i+1,comb,res,target);      

    }

    void BackTrack(vector<int>& candidates,int idx,vector<int>& comb,vector<vector<int>>& res, int target)
    {
        if (target==0)
        {
            res.push_back(comb);
            return;
        }

        if (target<0) return;

        for (int i=idx;i<n;i++)
        {
            comb.push_back(candidates[i]);
            BackTrack(candidates,i,comb,res,target-candidates[i]);
            comb.pop_back();

        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>> res;
        vector<int> comb;
        //CombSum(candidates,0,comb,res,target);
        BackTrack(candidates,0,comb,res,target); // more optimised
        
        return res;
    }
};