class Solution{
public:
string shortestPalindrome(string s){
string r=s;
reverse(r.begin(),r.end());
string t=s+"#"+r;
vector<int>l(t.size());
for(int i=1;i<t.size();i++){
int j=l[i-1];
while(j&&t[i]!=t[j])j=l[j-1];
if(t[i]==t[j])j++;
l[i]=j;
}
return r.substr(0,s.size()-l.back())+s;
}
};