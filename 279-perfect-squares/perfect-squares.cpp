class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i*i<=n;i++){
            int s=i*i;
            for(int j=s;j<=n;j++)dp[j]=min(dp[j],dp[j-s]+1);
        }
        return dp[n];
    }
};