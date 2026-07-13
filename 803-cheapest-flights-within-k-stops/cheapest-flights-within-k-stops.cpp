class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for (auto &it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].push_back({v, wt});
        }

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, {src, 0}});   // {stops, {node, cost}}

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int stops = top.first;
            int node = top.second.first;
            int cost = top.second.second;

            if (stops > k)
                continue;

            for (auto nbr : graph[node]) {

                int next = nbr.first;
                int wt = nbr.second;

                int newCost = cost + wt;

                if (newCost < dist[next]) {
                    dist[next] = newCost;
                    pq.push({stops + 1, {next, newCost}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};