class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right){
            pred = pred->right;
        }
        return pred;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            // Case 1: No child
            if(!root->left && !root->right) return NULL;

            // Case 2: One child
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            // Case 3: Two children
            TreeNode* pred = iop(root);
            root->val = pred->val;

            // Delete predecessor from left subtree
            root->left = deleteNode(root->left, pred->val);
        }

        return root;
    }
};