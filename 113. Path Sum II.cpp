class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void Backtrack(TreeNode* root, int target) {
        if (!root) return;

        curr.push_back(root->val);

        // If it's a leaf node and the remaining target is root->val
        if (!root->left && !root->right && target == root->val) {
            res.push_back(curr);
        } else {
            Backtrack(root->left, target - root->val);
            Backtrack(root->right, target - root->val);
        }

        curr.pop_back();  // Backtrack step
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        Backtrack(root, targetSum);
        return res;
    }
};
