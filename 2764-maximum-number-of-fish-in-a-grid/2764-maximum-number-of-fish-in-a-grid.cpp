#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Disjointset {
public:
    vector<int> rank, parent, size;
    Disjointset(int n) {
        size.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }
    int findUpar(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findUpar(parent[u]);
    }

    void unionByrank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;

        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;

        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBysize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        Disjointset ds(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int newidx = m * i + j;
                if (grid[i][j] > 0)
                    ds.size[newidx] = grid[i][j];
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int newidx = m * i + j;
                if (grid[i][j] > 0) {

                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                            grid[nx][ny] > 0) {
                            int newidx1 = m * nx + ny;
                            if (ds.findUpar(newidx) != ds.findUpar(newidx1)) {
                                ds.unionBysize(newidx, newidx1);
                            }
                        }
                    }
                }
            }
        }

        return *max_element(ds.size.begin(), ds.size.end());
    }
};