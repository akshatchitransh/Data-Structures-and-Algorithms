class Solution {
public:
    vector<string> ans;

    void dfs(string s, int i, int l, int r) {
        if (l == 0 && r == 0) {
            int c = 0;
            for (char x : s) {
                if (x == '(') c++;
                else if (x == ')') {
                    if (!c) return;
                    c--;
                }
            }
            if (!c) ans.push_back(s);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (j > i && s[j] == s[j - 1]) continue;
            if (l && s[j] == '(')
                dfs(s.substr(0, j) + s.substr(j + 1), j, l - 1, r);
            if (r && s[j] == ')')
                dfs(s.substr(0, j) + s.substr(j + 1), j, l, r - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l) l--;
                else r++;
            }
        }
        dfs(s, 0, l, r);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};