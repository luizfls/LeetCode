/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */ class Solution { public:
    bool isCompleteTree(TreeNode* root) {
        std::vector<bool> levelOrder;
        std::queue<TreeNode*> q({root});
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node != nullptr)
            {
                levelOrder.emplace_back(true);
                q.push(node->left);
                q.push(node->right);
            }
            else
                levelOrder.emplace_back(false);
        }
        auto firstFalse = std::find(levelOrder.cbegin(), levelOrder.cend(), false);
        for(auto it = firstFalse; it != levelOrder.cend(); ++it)
            if(*it == true)
                return false;
        return true;
    }
};
