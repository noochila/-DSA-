class Solution {
    vector<int> evenSubtree1, oddSubtree1, totalEven1, totalOdd1;
    vector<int> evenSubtree2, oddSubtree2, totalEven2, totalOdd2;
    vector<vector<int>> gr1, gr2;

    void dfs1Tree1(int node, int parent) {
        evenSubtree1[node] = 1; // Node itself at distance 0 (even)
        oddSubtree1[node] = 0;
        for (int ne : gr1[node]) {
            if (ne != parent) {
                dfs1Tree1(ne, node);
                evenSubtree1[node] += oddSubtree1[ne];
                oddSubtree1[node] += evenSubtree1[ne];
            }
        }
    }

    void dfs2Tree1(int node, int parent, int evenAbove, int oddAbove) {
        totalEven1[node] = evenSubtree1[node] + evenAbove;
        totalOdd1[node] = oddSubtree1[node] + oddAbove;

        for (int ne : gr1[node]) {
            if (ne != parent) {
                int evenUp = totalOdd1[node] - evenSubtree1[ne];
                int oddUp = totalEven1[node] - oddSubtree1[ne];

                dfs2Tree1(ne, node, evenUp, oddUp);
            }
        }
    }

    void dfs1Tree2(int node, int parent) {
        evenSubtree2[node] = 1; // Node itself at distance 0 (even)
        oddSubtree2[node] = 0;
        for (int ne : gr2[node]) {
            if (ne != parent) {
                dfs1Tree2(ne, node);
                evenSubtree2[node] += oddSubtree2[ne];
                oddSubtree2[node] += evenSubtree2[ne];
            }
        }
    }

    void dfs2Tree2(int node, int parent, int evenAbove, int oddAbove) {
        totalEven2[node] = evenSubtree2[node] + evenAbove;
        totalOdd2[node] = oddSubtree2[node] + oddAbove;

        for (int ne : gr2[node]) {
            if (ne != parent) {
                int evenUp = totalOdd2[node] - evenSubtree2[ne];
                int oddUp = totalEven2[node] - oddSubtree2[ne];

                dfs2Tree2(ne, node, evenUp, oddUp);
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        gr1.resize(n);
        for (auto& edge : edges1) {
            int node = edge[0], ne = edge[1];
            gr1[node].push_back(ne);
            gr1[ne].push_back(node);
        }

        gr2.resize(m);
        for (auto& edge : edges2) {
            int node = edge[0], ne = edge[1];
            gr2[node].push_back(ne);
            gr2[ne].push_back(node);
        }

        evenSubtree1.resize(n);
        oddSubtree1.resize(n);
        totalEven1.resize(n);
        totalOdd1.resize(n);
        dfs1Tree1(0, -1);
        dfs2Tree1(0, -1, 0, 0);

        evenSubtree2.resize(m);
        oddSubtree2.resize(m);
        totalEven2.resize(m);
        totalOdd2.resize(m);
        dfs1Tree2(0, -1);
        dfs2Tree2(0, -1, 0, 0);

        int goldenNode = 0;
        int maxTotalOdd = totalOdd2[0];
        for (int i = 1; i < m; i++) {
            if (totalOdd2[i] > maxTotalOdd) {
                maxTotalOdd = totalOdd2[i];
                goldenNode = i;
            }
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = totalEven1[i] + maxTotalOdd;
        }

        return answer;
    }
};