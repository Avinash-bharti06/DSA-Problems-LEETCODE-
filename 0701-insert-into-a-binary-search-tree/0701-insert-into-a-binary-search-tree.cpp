class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(root->val>val){
            if(root->left==NULL){
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
                return root;
            }
            else insertIntoBST(root->left,val);
        }
        if(root->val<val){
            if(root->right==NULL){
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
                return root;
            }
            else insertIntoBST(root->right,val);
        }
        return root;
    }
};