#include <map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    // Custom comparator for the priority queue
    struct comparator {
        bool operator()(const pair<char, int>& a,
                        const pair<char, int>& b) const {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first; // Min-heap based on the index
        }
    };

    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, comparator> pq;
     
      set<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});

            } else {
        
                if (!pq.empty()) {
                    st.insert(pq.top().second);
                    pq.pop();
                }
            }
        }
      
      

        string ans;
        for (int i = 0; i < s.size(); i++) {

            if(st.find(i)==st.end() && s[i]!='*')
            ans+=s[i];

          
        }

        return ans;
    }
};
