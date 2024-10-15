#include <vector>
#include <map>
#include <queue>

class Solution {
public:
    std::vector<int> findXSum(std::vector<int>& nums, int k, int x) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        std::map<int, int> mp;
        std::vector<int> ans;

        while (j < n) {
            // Add the current element to the map
            mp[nums[j]]++;

            // Check if we have reached the window size
            if (j - i + 1 == k) {
                int ele = 0;
                int y = x;

                // Use a priority queue to find the top x frequent elements
                std::priority_queue<std::pair<int, int>> pq;
                for (auto it : mp) {
                    pq.push({it.second, it.first});
                }

                // Sum the top x elements
                while (!pq.empty() && y > 0) {
                    ele += pq.top().first * pq.top().second;
                    pq.pop();
                    y--;
                }

                ans.push_back(ele);

                // Remove the element that is sliding out of the window from the map
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                // Slide the window
                i++;
            }

            // Expand the window
            j++;
        }

        return ans;
    }
};
