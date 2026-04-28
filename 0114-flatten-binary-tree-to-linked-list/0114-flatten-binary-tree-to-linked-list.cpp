class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& ans) {
        if(root == NULL) return;

        ans.push_back(root);          // store node (not value)
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    void flatten(TreeNode* root) {
        if(root == NULL) return;

        vector<TreeNode*> ans;
        preorder(root, ans);

        int n = ans.size();
        for(int i = 0; i < n - 1; i++) {
            ans[i]->left = NULL;
            ans[i]->right = ans[i+1];
        }

        if(n > 0) {
            ans[n-1]->left = NULL;
            ans[n-1]->right = NULL;
        }
    }
};