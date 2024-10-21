class Solution {
public:
    char solve(string s, int n, int k) {
        if (n == 0) {
            cout<<s<<endl;
            return s[k-1];
        } else {
            string temp = s;
            reverse(temp.begin(), temp.end());
            // cout<<temp<<endl;
              for(int i=0;i<temp.size();i++)
              {
                if(temp[i]=='1')
                temp[i]='0';
                else
                temp[i]='1';
              }
            //   cout<<temp<<endl;
            string newS = s + "1" + temp;
            // cout<<newS<<endl;
            return solve(newS, n - 1, k);
        }
    }

    char findKthBit(int n, int k) {

        string s = "0";
        return solve(s, n-1 , k);
    }
};