/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        computeHeight(root);
        return _diameter;
    }

    int computeHeight(TreeNode* root) {
        if(root == nullptr)
            return 0;

        auto leftHeight  = computeHeight(root->left);
        auto rightHeight = computeHeight(root->right);

        auto diameter = leftHeight + rightHeight;
        auto height = std::max(leftHeight, rightHeight) + 1;

        _diameter = std::max(_diameter, diameter);
        return height;
    }

private:
    int _diameter = 0;
};
