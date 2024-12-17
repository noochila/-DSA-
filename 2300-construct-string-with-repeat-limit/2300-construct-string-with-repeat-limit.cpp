class Solution {
public:
    string repeatLimitedString(string s, int c) {
        map<char, int> freq;

        for (char ch : s)
            freq[ch]++;

        priority_queue<pair<char, int>> pq;

        for (auto it : freq)
            pq.push({it.first, it.second});

        string result;

        while (!pq.empty()) {
            auto [ch, count] = pq.top();
            pq.pop();

            int limit = min(count, c);
            result.append(limit, ch);
            count -= limit;

            if (count > 0) {
                if (pq.empty())
                    break;

                auto [next_ch, next_count] = pq.top();
                pq.pop();

                result.push_back(next_ch);
                next_count--;

                if (next_count > 0)
                    pq.push({next_ch, next_count});

                pq.push({ch, count});
            }
        }

        return result;
    }
};
