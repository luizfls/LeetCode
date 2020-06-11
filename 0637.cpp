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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return {};

        std::vector<double> levelsAvg;
        int nodesAtLevel;

        std::queue<std::pair<TreeNode*, int>> q({{root, 0}});
        while(!q.empty())
        {
            auto [node, level] = q.front();
            q.pop();

            if(levelsAvg.size() == level)
            {
                levelsAvg.push_back(node->val);
                nodesAtLevel = 1;
            }
            else
            {
                levelsAvg[level] = (levelsAvg[level] * nodesAtLevel + node->val) / (nodesAtLevel + 1);
                nodesAtLevel++;
            }

            if(node->left != nullptr)
                q.push({node->left, level + 1});
            if(node->right != nullptr)
                q.push({node->right, level + 1});
        }

        return levelsAvg;
    }
};
