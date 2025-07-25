
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // vector<int> ans;
        // vector<int> hash(26, 0);
        // vector<int> phash(26, 0);
        // int window = p.size();
        // int len = s.size();
        // if(len < window)
        // {
        //     return ans;
        // }
        // int left = 0,right = 0;
        // while(right < window)
        // {
        //     phash[p[right] - 'a'] += 1;
        //     hash[s[right] - 'a'] += 1;
        //     right++;
        // }
        // right -=1;
        // while(right < len)
        // {
        //     if(phash == hash)
        //     {
        //         ans.push_back(left);
        //     }
        //     right+=1;
        //     if(right != len)
        //     {
        //         hash[s[right] - 'a'] += 1;
        //     }
        //     hash[s[left] - 'a'] -=1 ;
        //     left += 1;
        // }
        // return ans;


        // Time Complexity: O(m + n)
        // Space Complexity: O(26) = O(1)
        int slen=s.length(),plen=p.length();
        vector<int> res;
        if (plen>slen) return {};

        vector<int> sfreq(26,0),pfreq(26,0);
        for (int i=0;i<plen;i++) pfreq[p[i]-'a']++;
        
        int left=0,right=0;
        while (right<slen)
        {
            sfreq[s[right]-'a']++;

            if (right-left+1>plen)
            {
                sfreq[s[left]-'a']--;
                left++;
            }
            if (pfreq==sfreq) res.push_back(left);
            right++;
        }
        return res;
    }
};
