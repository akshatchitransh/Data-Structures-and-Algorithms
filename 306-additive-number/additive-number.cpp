class Solution {
public:
    string add(string a, string b) {
        string c;
        int i = a.size() - 1, j = b.size() - 1, t = 0;
        while (i >= 0 || j >= 0 || t) {
            if (i >= 0) t += a[i--] - '0';
            if (j >= 0) t += b[j--] - '0';
            c += char(t % 10 + '0');
            t /= 10;
        }
        reverse(c.begin(), c.end());
        return c;
    }

    bool isAdditiveNumber(string s) {
        int n = s.size();
        for (int i = 1; i <= n / 2; i++) {
            if (i > 1 && s[0] == '0') break;
            for (int j = 1; max(i, j) <= n - i - j; j++) {
                if (j > 1 && s[i] == '0') break;
                string a = s.substr(0, i);
                string b = s.substr(i, j);
                int k = i + j;
                while (k < n) {
                    string c = add(a, b);
                    if (s.substr(k, c.size()) != c) break;
                    k += c.size();
                    a = b;
                    b = c;
                }
                if (k == n) return true;
            }
        }
        return false;
    }
};