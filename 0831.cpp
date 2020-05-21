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

    std::string parsePhone(std::string& s)
    {
        // remove non-digits
        s.erase(std::remove_if(s.begin(), s.end(),
                               [](char c){ return !std::isdigit(c); }),
                s.end());

        // local number
        if(s.size() == 10)
        {
            s.replace(0, 6, 6, '*');
            s.insert(3, "-");
            s.insert(7, "-");
        }
        // international number
        else
        {
            auto cc_size = s.size() - 10;
            s.replace(0, cc_size + 6, cc_size + 6, '*');
            s.insert(0, "+");
            s.insert(cc_size + 1, "-");
            s.insert(cc_size + 5, "-");
            s.insert(cc_size + 9, "-");
        }

        return s;
    }
};
