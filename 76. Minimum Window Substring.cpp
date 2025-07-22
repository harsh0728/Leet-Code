// TC-? O(M+N)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        int left = 0, right = 0, matchCount = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for (char c : t) tmap[c]++;
        int desiredMatch = tmap.size();

        while (right < s.length()) {
            smap[s[right]]++;
            if (tmap.count(s[right]) && smap[s[right]] == tmap[s[right]]) matchCount++;

            while (matchCount == desiredMatch) 
            {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                smap[s[left]]--;
                if (tmap.count(s[left]) && smap[s[left]] < tmap[s[left]]) matchCount--;
                left++;
            }
            right++;
        }
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};

