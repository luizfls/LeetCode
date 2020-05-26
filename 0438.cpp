class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};

        std::array<int, 26> P{};
        for(auto c : p) ++P[c - 'a'];

        auto ss = s.substr(0, p.size());
        std::array<int, 26> S{};
        for(auto c : ss) ++S[c - 'a'];

        std::vector<int> indices;
        if(S == P)
            indices.emplace_back(0);
        for(int i = 1; i <= s.size() - p.size(); ++i)
        {
            auto removeChar = s[i - 1];
            auto addChar    = s[i + p.size() - 1];
            --S[removeChar - 'a'];
            ++S[addChar - 'a'];

            if(S == P)
                indices.emplace_back(i);
        }

        return indices;
    }
};
