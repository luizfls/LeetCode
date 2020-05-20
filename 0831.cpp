class Solution {
public:
    string maskPII(string S) {
        return (S.find('@') != std::string::npos)
            ? parseEmail(S)
            : parsePhone(S);
    }

private:
    std::string parseEmail(std::string& s)
    {
        auto at = s.find('@');
        s.erase(1, at - 2);
        s.insert(1, "*****");
        std::transform(s.begin(), s.end(), s.begin(),
                       [](char c){ return std::tolower(c); });
        return s;
    }

    std::string parsePhone(const std::string& s)
    {
        std::string digits;

        for(auto c : s)
            if(std::isdigit(c))
                digits += c;

        // local
        if(digits.size() == 10)
        {
            digits.replace(0, 6, 6, '*');
            digits.insert(3, "-");
            digits.insert(7, "-");
        }
        // international
        else
        {
            auto cc_size = digits.size() - 10;
            digits.replace(0, cc_size + 6, cc_size + 6, '*');
            digits.insert(0, "+");
            digits.insert(cc_size + 1, "-");
            digits.insert(cc_size + 5, "-");
            digits.insert(cc_size + 9, "-");
        }

        return digits;
    }
};
