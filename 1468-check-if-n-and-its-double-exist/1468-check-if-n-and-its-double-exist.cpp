class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        map<int, int> mp;
        for (auto it : arr)
            mp[it]++;

        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i] * 2) != mp.end()) {
                cout<<arr[i]<<endl;
                if (arr[i] == 0 && mp[0] > 1)
                    return true;
                else if (arr[i] == 0)
                    continue;
                else
                    return true;
            }
        }
        return false;
    }
};