// TC-> O(pow(4,N)*N)

class Solution {
public:

    unordered_map<char,string> dialpad_map={
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
    };


    void BackTrack(string digits,int idx,string& s,vector<string>& res)
    {
        if (idx>=digits.length())
        {
            res.push_back(s);
            return;
        }
        char c=digits[idx];
        string str= dialpad_map[c];

        for (int i=0;i<str.length();i++)
        {
            s.push_back(str[i]);
            BackTrack(digits,idx+1,s,res);
            s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) { 
    if (digits.empty()) return {};
    vector<string> res;
    string s="";

    BackTrack(digits,0,s,res);

    return res;

    }
};

