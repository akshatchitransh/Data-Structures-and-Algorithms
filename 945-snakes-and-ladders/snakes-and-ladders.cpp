class Solution {
public:
    pair<int, int> getCoordinates(int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        int row = n - 1 - r;
        int col = (r % 2 == 0) ? c : n - 1 - c;
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == n * n) return steps;

            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [r, c] = getCoordinates(next, n);
                int dest = (board[r][c] == -1) ? next : board[r][c];

                if (!vis[dest]) {
                    vis[dest] = true;
                    q.push({dest, steps + 1});
                }
            }
        }

        return -1;
    }
};