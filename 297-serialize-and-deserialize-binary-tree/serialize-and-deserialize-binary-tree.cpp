class Codec{
public:
string serialize(TreeNode*rt){
if(!rt)return "";
string s;
queue<TreeNode*>q;
q.push(rt);
while(!q.empty()){
TreeNode*nd=q.front();
q.pop();
if(!nd)s+="#,";
else{
s+=to_string(nd->val)+",";
q.push(nd->left);
q.push(nd->right);
}
}
return s;
}
TreeNode*deserialize(string s){
if(s.empty())return NULL;
stringstream ss(s);
string t;
getline(ss,t,',');
TreeNode*rt=new TreeNode(stoi(t));
queue<TreeNode*>q;
q.push(rt);
while(!q.empty()){
TreeNode*nd=q.front();
q.pop();
if(!getline(ss,t,','))break;
if(t!="#"){
nd->left=new TreeNode(stoi(t));
q.push(nd->left);
}
if(!getline(ss,t,','))break;
if(t!="#"){
nd->right=new TreeNode(stoi(t));
q.push(nd->right);
}
}
return rt;
}
};