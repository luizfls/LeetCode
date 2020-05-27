class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;

        std::array<int, 26> S1{};
        for(auto c : s1)
            ++S1[c - 'a'];

        auto ss = s2.substr(0, s1.size());
        std::array<int, 26> S2{};
        for(auto c : ss)
            ++S2[c - 'a'];

        std::vector<int> indices;
        if(S1 == S2)
            return true;
        for(int i = 1; i <= s2.size() - s1.size(); ++i)
        {
            auto removeChar = s2[i - 1];
            auto addChar    = s2[i + s1.size() - 1];
            --S2[removeChar - 'a'];
            ++S2[addChar - 'a'];

            if(S1 == S2)
                return true;
        }

        return false;
    }
};
