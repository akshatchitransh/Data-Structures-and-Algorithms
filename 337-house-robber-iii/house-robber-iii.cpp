class Solution{
public:
pair<int,int>dfs(TreeNode*rt){
if(!rt)return {0,0};
auto l=dfs(rt->left),r=dfs(rt->right);
int tk=rt->val+l.second+r.second;
int nt=max(l.first,l.second)+max(r.first,r.second);
return {tk,nt};
}
int rob(TreeNode*rt){
auto p=dfs(rt);
return max(p.first,p.second);
}
};