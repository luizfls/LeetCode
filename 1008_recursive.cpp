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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder_const(preorder);
    }

    TreeNode* bstFromPreorder_const(const vector<int>& preorder)
    {
        if(preorder.empty())
            return nullptr;

        auto root = new TreeNode(preorder.front());

        auto lessBegin = preorder.cend();
        auto lessEnd = preorder.cend();
        auto greaterBegin = preorder.cend();
        auto greaterEnd = preorder.cend();
        for(auto it = std::next(preorder.cbegin()); it != preorder.cend(); ++it)
        {
            if(*it < root->val && lessBegin == preorder.cend())
                lessBegin = it;
            else if(*it > root->val)
            {
                if(lessBegin != preorder.cend())
                    lessEnd = it;
                greaterBegin = it;
                break;
            }
        }

        root->left = bstFromPreorder_const({lessBegin, lessEnd});
        root->right = bstFromPreorder_const({greaterBegin, greaterEnd});

        return root;
    }
};
