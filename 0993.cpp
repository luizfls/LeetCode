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
    bool isCousins(TreeNode* root, int x, int y) {
        _xyMeta.reserve(2);

        std::queue<NodeTraversal> bfs({{root, 0, nullptr}});
        while(!bfs.empty())
        {
            auto nodeInfo = bfs.front();
            bfs.pop();

            if(nodeInfo.node->val == x || nodeInfo.node->val == y)
                _xyMeta.emplace_back(nodeInfo.meta);

            if(_xyMeta.size() == 2)
                break;
            else if(_xyMeta.size() == 1 && _xyMeta.front().depth < nodeInfo.meta.depth)
                return false;

            if(nodeInfo.node->left != nullptr)
                bfs.push({nodeInfo.node->left, {nodeInfo.meta.depth + 1, nodeInfo.node}});
            if(nodeInfo.node->right != nullptr)
                bfs.push({nodeInfo.node->right, {nodeInfo.meta.depth + 1, nodeInfo.node}});
        }

        auto sameDepth = _xyMeta.front().depth == _xyMeta.back().depth;
        auto differentParents = _xyMeta.front().parent != _xyMeta.back().parent;
        return sameDepth && differentParents;
    }

private:
    struct NodeMeta
    {
        int depth;
        TreeNode* parent;
    };

    struct NodeTraversal
    {
        TreeNode* node;
        NodeMeta meta;
    };

    std::vector<NodeMeta> _xyMeta;
};
