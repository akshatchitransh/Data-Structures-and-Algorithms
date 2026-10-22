/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st;
        st.push(root);
        vector<int>preorder;
        if(root==NULL) return preorder;
        while(!st.empty()){
            TreeNode* x = st.top();
            st.pop();
            preorder.push_back(x->val);
            if(x->right!=NULL){
                st.push(x->right);
            }
            if(x->left!=NULL){
                st.push(x->left);
            }
        }
    return preorder;}
};