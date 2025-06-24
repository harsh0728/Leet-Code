// Time Complexity-> O(2^n)

class Solution {
public:

    void Backtrack(string& s,int index,string& curr,vector<string>& res)
    {
        if (curr.length()==s.length())
        {
            res.push_back(curr);
            return;
        }

        char c=s[index];

        if (isalpha(c))
        {
            curr.push_back(tolower(c));
            Backtrack(s,index+1,curr,res);
            curr.pop_back();

            curr.push_back(toupper(c));
            Backtrack(s,index+1,curr,res);
            curr.pop_back();
        }
        else 
        {
            curr.push_back(c);
            Backtrack(s,index+1,curr,res);
            curr.pop_back();
        }
    
 
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string curr="";
        Backtrack(s,0,curr,res);
        return res;

    }
};