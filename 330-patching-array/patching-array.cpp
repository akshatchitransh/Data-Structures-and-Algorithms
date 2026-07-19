class Solution {
public:
    int minPatches(vector<int>& a, int n) {
        long long x = 1;
        int i = 0, c = 0;
        while (x <= n) {
            if (i < a.size() && a[i] <= x)
                x += a[i++];
            else {
                x += x;
                c++;
            }
        }
        return c;
    }
};