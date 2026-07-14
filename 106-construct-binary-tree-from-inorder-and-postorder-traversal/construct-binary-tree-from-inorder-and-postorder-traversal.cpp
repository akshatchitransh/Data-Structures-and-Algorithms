class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mp[root->val];
        int leftSize = inRoot - inStart;

        root->left = build(inorder, inStart, inRoot - 1,
                           postorder, postStart, postStart + leftSize - 1);

        root->right = build(inorder, inRoot + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }
};