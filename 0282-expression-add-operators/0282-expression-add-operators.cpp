#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;

    void solve(int ind, string temp, long long prev, long long curr, int target, string num) {
        if (ind == num.size()) {
            if (curr == target) {
                ans.push_back(temp);
            }
            return;
        }

        for (int i = ind; i < num.size(); i++) {
            // Avoid numbers with leading zero
            if (i > ind && num[ind] == '0') break;

            string val = num.substr(ind, i - ind + 1);
            long long num_val = stoll(val);

            if (ind == 0) {
                solve(i + 1, temp + val, num_val, num_val, target, num);
            } else {
                solve(i + 1, temp + '+' + val, num_val, curr + num_val, target, num);
                solve(i + 1, temp + '-' + val, -num_val, curr - num_val, target, num);
                solve(i + 1, temp + '*' + val, prev * num_val, curr - prev + (prev * num_val), target, num);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(0, "", 0, 0, target, num);
        return ans;
    }
};
