class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {

        vector<int> a(51, 0);
        vector<int> b(51, 0);

        int n = A.size();

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
          
                a[A[i] ]++;
                b[B[i]]++;
                int count = 0;
                for (int j = 0; j <= 50; j++)
                {
                    if (a[j] == b[j] && a[j]>0)
                        count++;
                }
                ans[i] = count;
            
        }

        return ans;
    }
};