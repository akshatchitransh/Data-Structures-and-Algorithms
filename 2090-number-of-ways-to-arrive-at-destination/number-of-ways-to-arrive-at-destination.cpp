class Solution {
public:

    const int MOD = 1e9 + 7;

    int dfs(int node, int dest,
            vector<vector<pair<int,int>>> &adj,
            vector<long long> &dist,
            vector<int> &dp){

        if(node == dest)
            return 1;

        if(dp[node] != -1)
            return dp[node];

        long long ways = 0;

        for(auto &[next, wt] : adj[node]){

            if(dist[node] + wt == dist[next]){

                ways = (ways + dfs(next, dest, adj, dist, dp)) % MOD;
            }
        }

        return dp[node] = ways;
    }

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : roads){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){

            auto [dis,node] = pq.top();
            pq.pop();

            if(dis > dist[node])
                continue;

            for(auto &[next, wt] : adj[node]){

                long long newDist = dis + wt;

                if(newDist < dist[next]){

                    dist[next] = newDist;
                    pq.push({newDist,next});
                }
            }
        }

        vector<int> dp(n,-1);

        return dfs(0,n-1,adj,dist,dp);
    }
};