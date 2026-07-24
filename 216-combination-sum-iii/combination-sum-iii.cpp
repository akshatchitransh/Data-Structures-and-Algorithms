class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int x,int k,int n){
        if(k==0&&n==0){
            ans.push_back(cur);
            return;
        }
        if(k==0||n<0) return;
        for(int i=x;i<=9;i++){
            cur.push_back(i);
            dfs(i+1,k-1,n-i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1,k,n);
        return ans;
    }
};