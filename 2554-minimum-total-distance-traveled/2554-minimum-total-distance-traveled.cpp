class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(begin(robot), end(robot));
    sort(begin(factory), end(factory));
    vector<int>pos;
    for(auto &it : factory)
        for(int i = 0; i < it[1]; i++)
            pos.push_back(it[0]);
    int n = robot.size(), m = pos.size();
    vector<vector<long long>> dp(n, vector<long long>(m, -1));
    return f(0, 0, robot, pos, dp);
}

long long f(int i, int j, vector<int>& robot, vector<int>& pos, vector<vector<long long>>& dp) {
    if(i == robot.size()) return 0;
    if(j == pos.size()) return 1e12;
    if(dp[i][j] != -1) return dp[i][j];
    
    long long pick = abs(robot[i]-pos[j]) + f(i+1, j+1, robot, pos, dp);
    long long skip = f(i, j+1, robot, pos, dp);
    return dp[i][j] = min(pick, skip);
}
};