class Solution{
public:
bool f(vector<int>&s,int i,int k,unordered_map<long long,bool>&m){
if(i==s.size()-1)return 1;
long long z=((long long)i<<32)|k;
if(m.count(z))return m[z];
for(int d=k-1;d<=k+1;d++){
if(d>0){
int x=s[i]+d;
auto it=lower_bound(s.begin()+i+1,s.end(),x);
if(it!=s.end()&&*it==x&&f(s,it-s.begin(),d,m))
return m[z]=1;
}
}
return m[z]=0;
}
bool canCross(vector<int>&s){
if(s.size()>1&&s[1]!=1)return 0;
unordered_map<long long,bool>m;
return f(s,0,0,m);
}
};