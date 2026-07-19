class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n = w.size(), ans = 0;
        vector<int> m(n), l(n);

        for (int i = 0; i < n; i++) {
            l[i] = w[i].size();
            for (char c : w[i])
                m[i] |= 1 << (c - 'a');
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((m[i] & m[j]) == 0)
                    ans = max(ans, l[i] * l[j]);
            }
        }

        return ans;
    }
};