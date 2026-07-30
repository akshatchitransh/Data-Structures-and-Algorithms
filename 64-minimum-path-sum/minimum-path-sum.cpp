class Solution {
public:int dfs(vector<vector<int>>& grid,int i , int j,vector<vector<int>>&dp ){

    int n = grid.size();
    int m = grid[0].size();
    if(i>n-1||j>m-1||i<0||j<0) return  INT_MAX;
    if(i==n-1 && j==m-1) return dp[i][j]= grid[i][j];
if(dp[i][j]!= -1) return dp[i][j];
   int right = dfs(grid, i, j + 1,dp);
int down = dfs(grid, i + 1, j,dp);

int ans = min(right, down);

if (ans == INT_MAX)
    return   INT_MAX;

return  dp[i][j]= grid[i][j] + ans;
}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int i=0;
        int j=0;
       
       
       return dfs(grid,i,j,dp);
    }
};