class Solution {
public:
    vector<string> ans;

    void solve(int idx, int parts, string curr, string &s) {
        if (parts == 4 && idx == s.size()) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if (parts == 4 || idx == s.size()) return;

        string num = "";

        for (int i = idx; i < min(idx + 3, (int)s.size()); i++) {
            num += s[i];

            if (num.size() > 1 && num[0] == '0') break;

            if (stoi(num) <= 255) {
                solve(i + 1, parts + 1, curr + num + ".", s);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(0, 0, "", s);
        return ans;
    }
};