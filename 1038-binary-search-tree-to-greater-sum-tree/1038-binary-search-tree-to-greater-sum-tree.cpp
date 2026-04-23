class Solution {
public:
    int sum =0;
    void reverseInOrder(TreeNode* root){
        if(root==NULL) return;
        reverseInOrder(root->right);
        root->val += sum;
        sum = root->val;
        reverseInOrder(root->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseInOrder(root);
        return root;
    }
};