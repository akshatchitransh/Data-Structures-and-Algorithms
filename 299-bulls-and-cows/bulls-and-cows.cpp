class Solution {
public:
    string getHint(string s, string g) {
        vector<int> a(10), b(10);
        int x = 0, y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == g[i]) x++;
            else {
                a[s[i] - '0']++;
                b[g[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++)
            y += min(a[i], b[i]);
        return to_string(x) + "A" + to_string(y) + "B";
    }
};