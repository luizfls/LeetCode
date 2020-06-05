class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return {};

        std::string lcp;

        auto minSize = std::min_element(strs.begin(), strs.end(),
                                        [](const std::string s1, const std::string s2)
                                        { return s1.size() < s2.size(); })->size();

        for(std::size_t i = 0; i < minSize; ++i)
        {
            auto c = strs[0][i];
            for(const auto& str : strs)
                if(str[i] != c)
                    goto exit;

            lcp.push_back(c);
        }

        exit:
        return lcp;
    }
};
