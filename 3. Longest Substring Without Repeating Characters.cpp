class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // // Using Hash Map T.C-> O(N)
        // map<char, int> charMap;
        // int start = -1;
        // int maxLen = 0;
        
        // for (int i = 0; i < s.size(); i++) {
        //     if (charMap.count(s[i]) != 0) {
        //         start = max(start, charMap[s[i]]);
        //     }
        //     charMap[s[i]] = i;
        //     maxLen = max(maxLen, i-start);
        // }
        // return maxLen;

        // Using Set T.C-> O(N)
        unordered_set<char> st;
        int left=0,maxLen=0;

        for (int right=0;right<s.length();right++)
        {
            char c=s[right]; // current character
            while (st.find(c)!=st.end()) 
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;

    }
};


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     int n1= s.size();
//     int ans=0;
//     int initial=-1;
//     vector<int> v(200,-1);
//         for(int i=0; i<n1; i++){
//         if(v[s[i]]>initial)
//         initial= v[s[i]];
//         v[s[i]]=i;
//         ans= max(ans,i-initial);
//         }
//     return ans;
//     }
// };

