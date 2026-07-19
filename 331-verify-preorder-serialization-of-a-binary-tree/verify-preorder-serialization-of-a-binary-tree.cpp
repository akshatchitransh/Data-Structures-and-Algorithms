class Solution {
public:
    bool isValidSerialization(string s) {
        int d = 1, i = 0, n = s.size();
        while (i < n) {
            if (d == 0) return false;
            if (s[i] == '#') {
                d--;
                i++;
            } else {
                while (i < n && s[i] != ',') i++;
                d++;
            }
            if (i < n && s[i] == ',') i++;
        }
        return d == 0;
    }
};