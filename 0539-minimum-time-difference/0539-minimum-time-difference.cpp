class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vec;
        for(const auto & timePoint : timePoints){
            int h = (timePoint[0]-'0')*10 + (timePoint[1]-'0');
            int m = (timePoint[3]-'0')*10 + (timePoint[4]-'0');

            int mins = h*60 + m;
            vec.push_back(mins);
        }
        sort(vec.begin(),vec.end());
        int res = INT_MAX;
        for(int i=1; i<vec.size(); i++){
            res = min(vec[i]-vec[i-1],res);
        }
        return min(res,1440+vec[0] - vec.back());
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();