class Solution {
public:
    int row, col;

    void dfs(vector<vector<char>>& brd, int rww, int cll) {
        if (rww < 0 || cll < 0 || rww >= row || cll >= col || brd[rww][cll] != 'O')
            return;

        brd[rww][cll] = '#';

        dfs(brd, rww + 1, cll);
        dfs(brd, rww - 1, cll);
        dfs(brd, rww, cll + 1);
        dfs(brd, rww, cll - 1);
    }

    void solve(vector<vector<char>>& brd) {
        row = brd.size();
        col = brd[0].size();

        for (int iii = 0; iii < row; iii++) {
            dfs(brd, iii, 0);
            dfs(brd, iii, col - 1);
        }

        for (int jjj = 0; jjj < col; jjj++) {
            dfs(brd, 0, jjj);
            dfs(brd, row - 1, jjj);
        }

        for (int iii = 0; iii < row; iii++) {
            for (int jjj = 0; jjj < col; jjj++) {
                if (brd[iii][jjj] == 'O') brd[iii][jjj] = 'X';
                else if (brd[iii][jjj] == '#') brd[iii][jjj] = 'O';
            }
        }
    }
};