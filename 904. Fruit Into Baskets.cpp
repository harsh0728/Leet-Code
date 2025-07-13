// Time Complexity-> O(n)
// Space Complexity-> O(1) 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int count=INT_MIN;
        int left=0,right=0;
        while (right<fruits.size())
        {
            basket[fruits[right]]++;
            if (basket.size()>2)
            {
                if (--basket[fruits[left]]==0) basket.erase(fruits[left]);
                left++;
            }
            count=max(count,right-left+1);
            right++;
        }
        return count;
    }
};
