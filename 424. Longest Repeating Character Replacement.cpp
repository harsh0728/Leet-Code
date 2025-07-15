// TC-> O(N)
// SC-> O(26)-> O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,res=0,max_count=0;
        unordered_map<char,int> mp;
        while (right<s.length())
        {
            // using map
            //mp[s[right]]++;
            //max_count=max(max_count,mp[s[right]]);
            
            // using vector
            freq[s[right]-'A']++;
            max_count=max(max_count,freq[s[right]-'A']);
            
            int window_size=right-left+1;
            if (window_size-max_count>k)
            {
                //mp[s[left]]--; // using map
                freq[s[left]-'A']--; // using vector
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};
