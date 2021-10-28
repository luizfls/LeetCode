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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr)
        { return nullptr; }
        if(root1 == nullptr)
        { return new TreeNode(root2->val, root2->left, root2->right); }
        if(root2 == nullptr)
        { return new TreeNode(root1->val, root1->left, root1->right); }

        auto n = new TreeNode(root1->val + root2->val);
        n->left = mergeTrees(root1->left, root2->left);
        n->right = mergeTrees(root1->right, root2->right);
        return n;
    }
};
