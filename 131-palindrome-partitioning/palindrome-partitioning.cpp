class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;

    bool pal(string &str, int lft, int rgt) {
        while (lft < rgt) {
            if (str[lft++] != str[rgt--]) return false;
        }
        return true;
    }

    void dfs(string &str, int idx) {
        if (idx == str.size()) {
            ans.push_back(cur);
            return;
        }

        for (int end = idx; end < str.size(); end++) {
            if (pal(str, idx, end)) {
                cur.push_back(str.substr(idx, end - idx + 1));
                dfs(str, end + 1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string str) {
        dfs(str, 0);
        return ans;
    }
};