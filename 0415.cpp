class Solution {
public:
    string addStrings(string num1, string num2) {
        auto n1s = num1.size();
        auto n2s = num2.size();
        if(n1s != n2s)
        {
            auto diff = std::max(n1s, n2s) - std::min(n1s, n2s);
            auto& shorter = n1s < n2s ? num1 : num2;
            shorter.insert(0, std::string(diff, '0'));
        }

        std::string result;
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        bool carry = false;
        while(it1 != num1.rend() && it2 != num2.rend())
        {
            auto sum = (*it1++ - '0') + (*it2++ - '0') + (carry ? 1 : 0);
            carry = sum >= 10;
            sum %= 10;
            result.push_back(sum + '0');
        }
        if(carry)
            result.push_back('1');

        std::reverse(result.begin(), result.end());

        return result;
    }
};
