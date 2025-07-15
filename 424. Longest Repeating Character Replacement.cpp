// TC-> O(N)
// SC-> O(26)-> O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,res=0,max_count=0;
        unordered_map<char,int> mp;
        while (right<s.length())
        {
            mp[s[right]]++;
            max_count=max(max_count,mp[s[right]]);
            int window_size=right-left+1;
            if (window_size-max_count>k)
            {
                mp[s[left]]--;
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};
