class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c){ return !std::isalnum(c); }), s.end());
        for(std::size_t i = 0; i < s.size() / 2; ++i)
            if(s[i] != s[s.size() - 1 - i])
                return false;
        return true;
    }
};
