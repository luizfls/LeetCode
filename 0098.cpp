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
    bool isValidBST(TreeNode* root) {
        std::vector<int> v;
        collect(root, v);
        return std::is_sorted(v.begin(), v.end()) && std::adjacent_find(v.begin(), v.end()) == v.end();
    }

private:
    void collect(TreeNode* root, std::vector<int>& v)
    {
        if(root == nullptr) return;
        collect(root->left, v);
        v.push_back(root->val);
        collect(root->right, v);
    }
};
