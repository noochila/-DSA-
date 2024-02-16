#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        std::map<int, int> mp;

        // Count frequency of each element
        for (int num : arr) {
            mp[num]++;
        }

        // Convert the map to a vector of pairs
        std::vector<std::pair<int, int>> sortedVector;
        for (const auto& entry : mp) {
            sortedVector.push_back(entry);
        }

        // Sort the vector based on frequency
        std::sort(sortedVector.begin(), sortedVector.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        // Reduce frequencies based on available k
        for (auto& entry : sortedVector) {
            if (k >= entry.second) {
                k -= entry.second;
                entry.second = 0;
            } else {
                entry.second -= k;
                k = 0;
            }
        }

        // Count the remaining elements with non-zero frequency
        int result = 0;
        for (const auto& entry : sortedVector) {
            if (entry.second > 0) {
                result++;
            }
        }

        return result;
    }
};
