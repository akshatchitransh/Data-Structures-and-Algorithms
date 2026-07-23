class Solution {
public:
    Node* connect(Node* rt) {
        if(!rt) return rt;
        queue<Node*> q;
        q.push(rt);
        while(!q.empty()){
            int sz=q.size();
            Node* pr=nullptr;
            while(sz--){
                Node* nd=q.front();
                q.pop();
                if(pr) pr->next=nd;
                pr=nd;
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
        }
        return rt;
    }
};