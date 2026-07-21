class Solution{
public:
int coinChange(vector<int>&a,int x){
vector<int>dp(x+1,1e9);
dp[0]=0;
for(int i=1;i<=x;i++)
for(int c:a)
if(i>=c)dp[i]=min(dp[i],dp[i-c]+1);
return dp[x]==1e9?-1:dp[x];
}
};