class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    vector<int> nlevel(TreeNode* root, int curr, int level){
        vector<int> ans;
        if(root == NULL) return ans;

        if(curr == level){
            ans.push_back(root->val);
            return ans;
        }

        vector<int> left = nlevel(root->left, curr+1, level);
        vector<int> right = nlevel(root->right, curr+1, level);

        // merge left and right
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = levels(root);
        vector<vector<int>> req;

        for(int i = 1; i <= level; i++){
            req.push_back(nlevel(root, 1, i));
        }

        return req;
    }
};