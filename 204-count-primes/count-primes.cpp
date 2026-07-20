class Solution {
public:
    int countPrimes(int num) {
        if (num <= 2) return 0;

        vector<bool> vis(num, true);
        vis[0] = vis[1] = false;

        for (int iii = 2; iii * iii < num; iii++) {
            if (vis[iii]) {
                for (int jjj = iii * iii; jjj < num; jjj += iii) {
                    vis[jjj] = false;
                }
            }
        }

        int ans = 0;

        for (int iii = 2; iii < num; iii++) {
            if (vis[iii]) ans++;
        }

        return ans;
    }
};