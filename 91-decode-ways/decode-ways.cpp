class Solution {
public:
    int solve(int idx, string &s, vector<int> &dp) {
        if (idx == s.size()) return 1;

        if (dp[idx] != -1) return dp[idx];

        if (s[idx] == '0') return dp[idx] = 0;

        int ways = solve(idx + 1, s, dp);

        if (idx + 1 < s.size()) {
            int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
            if (num >= 10 && num <= 26) {
                ways += solve(idx + 2, s, dp);
            }
        }

        return dp[idx] = ways;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, dp);
    }
};