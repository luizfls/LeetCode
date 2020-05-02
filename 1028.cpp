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
private:
    int parseNumber(const std::string& str, std::size_t start, std::size_t& nParsed)
    { return std::stoi(str.substr(start), &nParsed); }

    std::size_t parseDashes(const std::string& str, std::size_t start)
    { return str.find_first_not_of('-', start) - start; }

public:
    TreeNode* recoverFromPreorder(std::string str) {
        std::size_t i;
        auto number = parseNumber(str, 0, i);
        std::stack<TreeNode*> s({new TreeNode(number)});

        bool goingRight;
        while(i < str.size()) // iterate through string
        {
            if(std::isdigit(str[i])) // number
            {
                std::size_t nParsed;
                auto number = parseNumber(str, i, nParsed);
                auto node = new TreeNode(number);
                if(!goingRight)
                    s.top()->left = node;
                else
                    s.top()->right = node;
                s.push(node);
                i += nParsed;
            }
            else // dashes
            {
                auto nDashes = parseDashes(str, i);
                auto nPop = s.size() - nDashes;
                for(std::size_t j = 0; j < nPop; ++j)
                    s.pop();
                goingRight = nPop > 0u;
                i += nDashes;
            }
        }

        while(s.size() > 1u)
            s.pop();

        auto root = s.top();
        s.pop();
        return root;
    }
};
