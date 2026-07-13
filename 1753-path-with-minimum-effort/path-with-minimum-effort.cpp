class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        pq.push({0, {0, 0}});

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int effort = cur.first;
            int row = cur.second.first;
            int col = cur.second.second;

            if (visited[row][col])
                continue;

            visited[row][col] = true;

            if (row == n - 1 && col == m - 1)
                return effort;

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {

                    int newEffort = max(
                        effort,
                        abs(heights[row][col] - heights[nr][nc])
                    );

                    pq.push({newEffort, {nr, nc}});
                }
            }
        }

        return 0;
    }
};