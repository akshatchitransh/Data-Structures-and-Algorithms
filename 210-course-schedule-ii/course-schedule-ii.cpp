class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> deg(num, 0);

        for (auto &edg : pre) {
            adj[edg[1]].push_back(edg[0]);
            deg[edg[0]]++;
        }

        queue<int> que;

        for (int iii = 0; iii < num; iii++) {
            if (deg[iii] == 0) que.push(iii);
        }

        vector<int> ans;

        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            ans.push_back(cur);

            for (int nxt : adj[cur]) {
                deg[nxt]--;
                if (deg[nxt] == 0) que.push(nxt);
            }
        }

        if (ans.size() != num) return {};

        return ans;
    }
};