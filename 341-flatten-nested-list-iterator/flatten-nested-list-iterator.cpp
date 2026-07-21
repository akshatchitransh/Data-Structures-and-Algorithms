class NestedIterator{
public:
vector<int>v;
int i=0;
void dfs(vector<NestedInteger>&a){
for(auto &x:a){
if(x.isInteger())v.push_back(x.getInteger());
else{
auto t=x.getList();
dfs(t);
}
}
}
NestedIterator(vector<NestedInteger>&a){
dfs(a);
}
int next(){
return v[i++];
}
bool hasNext(){
return i<v.size();
}
};