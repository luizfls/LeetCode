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
    int maxPathSum(TreeNode* root) {
        computeMaxPathSum(root);
        return _maxPathSum;
    }

    int computeMaxPathSum(TreeNode* root) {
        int left_mps = 0;
        if(root->left != nullptr)
            left_mps = computeMaxPathSum(root->left);

        int right_mps = 0;
        if(root->right != nullptr)
            right_mps = computeMaxPathSum(root->right);

        auto alone      = root->val;
        auto with_left  = root->val + left_mps;
        auto with_right = root->val + right_mps;
        auto with_both  = root->val + left_mps + right_mps;

        int curr_mps;
        if(root->left != nullptr && root->right != nullptr)
            curr_mps = std::max({left_mps, right_mps, alone, with_left, with_right, with_both});
        else if(root->left != nullptr)
            curr_mps = std::max({left_mps, alone, with_left});
        else if(root->right != nullptr)
            curr_mps = std::max({right_mps, alone, with_right});
        else
            curr_mps = alone;

        _maxPathSum = std::max(_maxPathSum, curr_mps);

        if(root->left != nullptr && root->right != nullptr)
            return std::max({alone, with_left, with_right});
        else if(root->left != nullptr)
            return std::max(alone, with_left);
        else if(root->right != nullptr)
            return std::max(alone, with_right);
        else
            return alone;
    }

private:
    int _maxPathSum = std::numeric_limits<int>::min();
};
