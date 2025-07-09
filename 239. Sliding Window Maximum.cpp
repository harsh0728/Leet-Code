class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> heap;
        vector<int> res;

        // using priority queue  // T.C-> O(n log k)
        // for (int i=0;i<nums.size();i++)
        // {
        //     heap.push({nums[i],i});
        //     if (i>=k-1)
        //     {
        //         while (heap.top().second<=i-k)
        //         {
        //             heap.pop();
        //         }
        //         res.push_back(heap.top().first);
        //     }
        // }

        // using deque   // T.C-> O(N)
        deque<int> dq;
        for (int i=0;i<nums.size();i++)
        {
            while (!dq.empty() && dq.front()== i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};