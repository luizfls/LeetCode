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
        if(preorder.empty())
            return nullptr;

        auto root = new TreeNode(preorder.front());
        std::stack<TreeNode*> st({root});
        for(auto it = std::next(preorder.cbegin()); it != preorder.cend(); ++it)
        {
            auto val = *it;

            if(val < st.top()->val)
            {
                auto node = new TreeNode(val);
                st.top()->left = node;
                st.push(node);
            }
            else /* val > st.top()->val */
            {
                TreeNode* last;
                while(!st.empty() && val > st.top()->val)
                {
                    last = st.top();
                    st.pop();
                }
                auto node = new TreeNode(val);
                last->right = node;
                st.push(node);
            }
        }

        return root;
    }
};
