class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* c = root;

        while(c){
            if(c->left){
                TreeNode* p = c->left;

                // find inorder predecessor
                while(p->right && p->right != c) 
                    p = p->right;

                if(p->right == NULL){
                    // create thread
                    p->right = c;
                    c = c->left;
                }
                else{
                    // remove thread
                    p->right = NULL;
                    ans.push_back(c->val);
                    c = c->right;
                }
            }
            else{
                ans.push_back(c->val);
                c = c->right;
            }
        }
        return ans;
    }
};