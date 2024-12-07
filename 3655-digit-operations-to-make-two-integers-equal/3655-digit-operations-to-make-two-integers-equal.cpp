class Solution {
public:
    unordered_map<int, int> prime_map;

    void calc() {
        vector<bool> is_prime(10001, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= 10000; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= 10000; j += i)
                    is_prime[j] = false;
            }
        }

        for (int i = 2; i <= 10000; i++) {
            if (is_prime[i])
                prime_map[i] = 1;
        }
    }

    int minOperations(int n, int m) {
        
        calc();
        if (prime_map.find(n) != prime_map.end() || prime_map.find(m) != prime_map.end())
            return -1;

        set<int> visited;
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>> pq;

        pq.push({n, n});
        visited.insert(n);

        while (!pq.empty()) {
            auto [current_cost, current] = pq.top();
            pq.pop();

            if (current == m)
                return current_cost;

            string current_str = to_string(current);
            int len = current_str.size();

            for (int i = 0; i < len; i++) {
                int digit = current_str[i] - '0';

                for (int delta : {-1, 1}) {
                    int new_digit = digit + delta;
                    if (new_digit >= 0 && new_digit <= 9) {
                        string new_str = current_str;
                        new_str[i] = char(new_digit + '0');

                        int new_num = stoi(new_str);
                        if (prime_map.find(new_num) == prime_map.end() && visited.find(new_num) == visited.end()) {
                            visited.insert(new_num);
                            pq.push({current_cost + new_num, new_num});
                        }
                    }
                }
            }
        }

        return -1;
    }
};