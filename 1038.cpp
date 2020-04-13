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
    std::set<int> readValues(TreeNode* root)
    {
        if(root == nullptr)
            return {};

        std::set<int> values{root->val};

        auto valuesLeft = readValues(root->left);
        values.insert(valuesLeft.begin(), valuesLeft.end());

        auto valuesRight = readValues(root->right);
        values.insert(valuesRight.begin(), valuesRight.end());

        return values;
    }

    std::map<int, int> computeNewValues(std::set<int> oldValues)
    {
        std::map<int, int> old2new;
        auto totalSum = std::accumulate(oldValues.begin(), oldValues.end(), 0);
        int n = 0;
        for(auto oldValue : oldValues)
        {
            old2new[oldValue] = totalSum - n;
            n += oldValue;
        }
        return old2new;
    }

    TreeNode* bstToGst(TreeNode* root)
    {
        auto oldValues = readValues(root);
        auto old2new = computeNewValues(oldValues);
        return bstToGst_rec(root, old2new);
    }

    TreeNode* bstToGst_rec(TreeNode* root, std::map<int, int> old2new)
    {
        if(root == nullptr)
            return nullptr;

        root->val = old2new[root->val];
        root->left = bstToGst_rec(root->left, old2new);
        root->right = bstToGst_rec(root->right, old2new);

        return root;
    }
};
