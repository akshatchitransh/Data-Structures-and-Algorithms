class Solution {
public:
    vector<int> bt, ans;

    void add(int i) {
        while (i < bt.size()) {
            bt[i]++;
            i += i & -i;
        }
    }

    int qry(int i) {
        int s = 0;
        while (i) {
            s += bt[i];
            i -= i & -i;
        }
        return s;
    }

    vector<int> countSmaller(vector<int>& a) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        int n = a.size();
        bt.assign(b.size() + 2, 0);
        ans.assign(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
            ans[i] = qry(x - 1);
            add(x);
        }
        return ans;
    }
};