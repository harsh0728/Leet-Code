class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Approach 1
        // // T.C -> O(N)
        // vector<int> s1hash(26,0);
        // vector<int> s2hash(26,0);
        // int s1len=s1.size();
        // int s2len=s2.size();

        // if (s1len>s2len) return false;
        // int right=0;
        // while (right<s1len)
        // {
        //     s1hash[s1[right]-'a']++;
        //     s2hash[s2[right]-'a']++;
        //     right++;
        // }
        // right--;
        // int left=0;
        // while (right<s2len)
        // {
        //     if (s1hash==s2hash) return true;
        //     right++;
        //     if (right!=s2len)
        //     {
        //         s2hash[s2[left]-'a']--;
        //         s2hash[s2[right]-'a']++;
        //         left++;
        //     }
        // }
        // return false;

        // Approach 2
        // Sorting Technique
        //T.C : O((m-n) * nlogn)
        //S.C : O(n)
        if (s1.length()>s2.length()) return false;
        // sort(s1.begin(),s1.end());
        // for (int i=0;i<=s2.length()-s1.length();i++)
        // {
        //     string substring=s2.substr(i,s1.length());
        //     sort (begin(substring),end(substring));
        //     if (s1==substring) return true;
        // }
        // return false;

        // // Approach 3
        // // Using Hash Map
        // Time Complexity: O(N * 26) → O(N)
        // Space Complexity: O(26) = O(1)

        // unordered_map<char,int> mp1,mp2;
        // for (int i=0;i<s1.length();i++) 
        // {
        //     mp1[s1[i]]++;
        // }
        // int i=0,j=0;
        // while (j<s2.length())
        // {
        //     mp2[s2[j]]++;
        //     if (j-i+1>s1.length())
        //     {
        //         mp2[s2[i]]--;
        //         if (mp2[s2[i]] == 0) mp2.erase(s2[i]);
        //         i++;
        //     }
        //     if (mp1==mp2) return true; 
        //     j++;
        // }
        // return false;

        // Approach 4
        // Using Vector
        // Time Complexity: O(m + n)
        // Space Complexity: O(26) → O(1)

        int n = s1.length();
        int m = s2.length();

        // If s1 is larger than s2, no permutation can exist
        if (n > m) return false;

        // Frequency vectors for s1 and the current window in s2
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        // Fill frequency of characters in s1
        for (int i = 0; i < n; i++) {
            s1_freq[s1[i] - 'a']++;
        }

        // Slide the window over s2
        int i = 0; // left index of the sliding window
        int j = 0; // right index of the sliding window
        while (j < m) {
            // Include a new character from the right end of the window
            s2_freq[s2[j] - 'a']++;

            // Check if the current window size matches the size of s1
            if (j - i + 1 > n) {
                // If we have passed the size of s1, we need to remove the leftmost character
                s2_freq[s2[i] - 'a']--;
                i++;
            }

            // Check if the current window's frequency matches s1's frequency
            if (s1_freq == s2_freq) {
                return true;
            }

            j++;
        }

        // No matching window found
        return false;

    }
};
