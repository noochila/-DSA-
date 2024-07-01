

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();

        for (int it : asteroids) {
            bool destroyed = false;
            while (!s.empty() && s.top() > 0 && it < 0) {
                if (s.top() < -it) {
                    s.pop();
                } else if (s.top() == -it) {
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                s.push(it);
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
