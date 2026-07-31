class Solution{
public:
unordered_map<string,multiset<string>>g;
vector<string>a;
void f(string s){
while(g[s].size()){
auto it=g[s].begin();
string t=*it;
g[s].erase(it);
f(t);
}
a.push_back(s);
}
vector<string> findItinerary(vector<vector<string>>& t){
for(auto&i:t)g[i[0]].insert(i[1]);
f("JFK");
reverse(a.begin(),a.end());
return a;
}
};