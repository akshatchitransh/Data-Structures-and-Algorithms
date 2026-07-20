class Solution {
public:
int rec(int i , int j,int &ans,int m , int n, vector<vector<int>>&dp){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int right = rec(i , j+1,ans,m,n,dp);
    int down = rec(i+1,j,ans,m,n,dp);
    ans = right + down;
    return dp[i][j]= ans;
}
    int uniquePaths(int m, int n) {
        int ans =0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return  rec(0,0,ans,m,n,dp);
    }
};