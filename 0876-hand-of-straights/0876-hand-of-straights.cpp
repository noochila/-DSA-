#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool isNStraightHand(std::vector<int> &arr, int g)
    {
        // sort(hand.begin(), hand.end());

        // while (!hand.empty()) {
        //     std::vector<int> demo;
        //     demo.push_back(hand.front());
        //     hand.erase(hand.begin());

        //     for (int j = 0; j < groupSize - 1; ++j) {
        //         auto it = std::find(hand.begin(), hand.end(), demo.back() + 1);
        //         if (it != hand.end()) {
        //             demo.push_back(*it);
        //             hand.erase(it);
        //         } else {
        //             return false; // Sequence cannot be formed
        //         }
        //     }

        // }

        // return true;

        if (arr.size() % g != 0)
            return false;

        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it : mp)
            pq.push(it.first);

        while (!pq.empty())
        {

            vector<int> demo;
            cout << pq.top() << endl;
            demo.push_back(pq.top());
            mp[pq.top()]--;
            pq.pop();

            if (pq.empty() && g!=1)
                return false;

            for (int i = 0; i < g - 1 && !pq.empty(); i++)
            {

                if (demo.back() + 1 == pq.top())
                {
                    if (mp[pq.top()] != 0)
                    {
                        cout << pq.top() << endl;
                        mp[pq.top()]--;
                        demo.push_back(pq.top());
                        pq.pop();
                    }
                    else
                        return false;
                }
                else

                {
                    return false;
                }
            }

            for (auto it : demo)
            {
                if (mp[it] > 0)
                    pq.push(it);
            }
        }
        return true;
    }
};
