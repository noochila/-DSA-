class Solution {
public:

  int getDigitsum(int n)
  {
       int sum=0;
       while(n>0)
       {
        sum+=n%10;
        n=n/10;
       }
       return sum;
  }
    int minElement(vector<int>& nums) {



     vector<int> temp;
     for(auto it:nums)
     {
         temp.push_back(getDigitsum(it));
     }
     return *min_element(temp.begin(),temp.end());


        
    }
};