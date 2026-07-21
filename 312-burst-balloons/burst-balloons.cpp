class Solution{
public:
int dp[305][305];
int f(int l,int r,vector<int>&a){
if(l>r)return 0;
if(dp[l][r]!=-1)return dp[l][r];
int ans=0;
for(int i=l;i<=r;i++)ans=max(ans,a[l-1]*a[i]*a[r+1]+f(l,i-1,a)+f(i+1,r,a));
return dp[l][r]=ans;
}
int maxCoins(vector<int>&a){
a.insert(a.begin(),1);
a.push_back(1);
memset(dp,-1,sizeof(dp));
return f(1,a.size()-2,a);
}
};