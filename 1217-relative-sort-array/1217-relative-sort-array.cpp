class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        map<int,int>mp;

        for(int i=0;i<arr1.size();i++)
        {
            mp[arr1[i]]++;
        }


        
        int j=0;

        for(int i=0;i<arr2.size();i++)
        {
            while(mp[arr2[i]]>0)
            {
                arr1[j++]=arr2[i];
                mp[arr2[i]]--;
                if(mp[arr2[i]]==0)
                mp.erase(arr2[i]);

                cout<<arr1[j-1] <<" ";
                
            }

        }




        for(auto it:mp)
        {
          while(it.second>0)
          {
            arr1[j++]=it.first;
               cout<<arr1[j-1] <<" ";
            it.second--;
          }
        }


        return arr1;
        
    }
};