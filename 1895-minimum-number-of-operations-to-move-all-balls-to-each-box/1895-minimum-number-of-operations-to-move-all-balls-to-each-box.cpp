class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        int n=boxes.size();
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<i;j++)
            {
                if(boxes[j]=='1')
                {
                    c+=abs(i-j);
                }


            }

            for(int j=i+1;j<n;j++)
            {
                if(boxes[j]=='1')
                c+=abs(i-j);
            }
            ans.push_back(c);
        }

        return ans;
        
    }
};