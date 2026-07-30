class Solution {
public:
int dfs(vector<vector<int>>& obstacleGrid,int i , int j, vector<vector<int>>&dp ){
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if(i>n-1||j>m-1||i<0||j<0||obstacleGrid[i][j]==1) return  0;
    if(i==n-1 && j==m-1) return dp[i][j]= 1;
if(dp[i][j]!=-1) return dp[i][j];
    int right = dfs(obstacleGrid,i,j+1,dp);
    int left = dfs(obstacleGrid,i+1,j,dp);
    return dp[i][j] = left+right;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i=0;
        int j=0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return dfs(obstacleGrid,i,j,dp);
    }
};