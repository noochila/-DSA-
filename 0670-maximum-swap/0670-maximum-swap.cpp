class Solution {
public:
    int maximumSwap(int num) {

        // string s=to_string(num);

        // int n=s.size();
        // if(n==1)
        // return num;
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         string temp=s;
        //         ans=max(ans,stoi(temp));
        //         swap(temp[i],temp[j]);
        //         ans=max(ans,stoi(temp));

        //     }
        // }
        // return ans;

        string s = to_string(num);
        int n = s.size();
        vector<int> suffix(n);
        suffix[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[suffix[i + 1]])
                suffix[i] = i;
            else
                suffix[i] = suffix[i + 1];
        }

        for (int i = 0; i < n; i++) {

            if (suffix[i] == i)
                continue;
            else {
                if (s[suffix[i]] != s[i]) {
                    swap(s[suffix[i]], s[i]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};