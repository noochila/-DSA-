#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::map<char, int, std::greater<char>> mp;  // Use map with greater<char> to sort in descending order

        for (auto it : word)
            mp[it]++;

        std::vector<std::pair<char, int>> sortedPairs(mp.begin(), mp.end());

        // Custom comparator to sort based on values in descending order
        std::sort(sortedPairs.begin(), sortedPairs.end(),
                  [](const auto& a, const auto& b) {
                      return a.second > b.second || (a.second == b.second && a.first < b.first);
                  });

        // for (const auto& pair : sortedPairs)
        //     std::cout << pair.first << " " << pair.second << std::endl;

        int ans = 0;
        int val = 1;
        int len = 0;

        for (const auto& it : sortedPairs) {
           
            if (len % 8 == 0 && len != 0)
         
          val++;
        
            len++;
            
          

            ans += it.second * val;
        }

        return ans;
    }
};
