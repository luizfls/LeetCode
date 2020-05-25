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
    int deepestLeavesSum(TreeNode* root) {
        deepestLeavesSum(root, 0);
        return std::max_element(depth2sum.begin(), depth2sum.end())->second;
    }

    void deepestLeavesSum(TreeNode* node, int depth)
    {
        if(node != nullptr)
        {
            depth2sum[depth] += node->val;
            deepestLeavesSum(node->left, depth + 1);
            deepestLeavesSum(node->right, depth + 1);
        }
    }
private:
    std::unordered_map<int, int> depth2sum;
};
