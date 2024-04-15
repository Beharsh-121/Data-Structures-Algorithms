int solve(TreeNode* root, int curr){
        if(!root) return 0;
        curr = (curr*10) + root->val;
        if(!root->left && !root->right) return curr;
        int left = solve(root->left, curr);
        int right = solve(root->right, curr);
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }