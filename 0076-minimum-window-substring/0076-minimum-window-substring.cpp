// class Solution {
// public:
//     string minWindow(string a, string b) {
//         //  int len = 1e9;

//         //  string ans="";
//    string ans(1e5, ' ');

//   unordered_map<char, int> mp;
//   for (int i = 0; i < b.size(); i++)
//     mp[b[i]]++;

//   int i = 0;
//   int j = 0;
//   int n = a.size();
//   int count = mp.size();

//   while (j < n) {
//     if (mp.find(a[j]) != mp.end()) {
//       mp[a[j]]--;
//       if (mp[a[j]] == 0)
//         count--;

//       if (count == 0) {
//         while (count == 0) {
//     //         if(j-i+1<len)
//     //   {    len = min(len, j - i + 1);
//     //        ans=a.substr(i,j-i+1);
//     //   }
//    if(j-i+1<ans.size())
//    {
//        ans=a.substr(i,j-i+1);

//    }

//           if (mp.find(a[i]) != mp.end()) {
//             if (mp[a[i]] == 0) {
//               count++;
//             }

//             mp[a[i]]++;
//             i++;
//           } else
//             i++;
//         }
//         j++;

//       } else {
//         j++;
//       }

//     } else {
//       j++;
//     }
//   }
//   //   cout<<len<<endl;

//   if(ans.size()==1e5)
//   return "";

//   return ans;
        
//     }

// };
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (char c : t) {
            map[c]++;
        }

        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};