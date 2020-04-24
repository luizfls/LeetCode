class Solution {
public:
    string intToRoman(int num) {
        std::string roman;

        while(num > 0)
        {
            const auto& [value, symbol] = *std::prev(value2symbol.upper_bound(num));
            roman += symbol;
            num -= value;
        }

        return roman;
    }

private:
    static const std::map<int, std::string> value2symbol;
};

const std::map<int, std::string> Solution::value2symbol = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
                                                           {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
                                                           {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
                                                           {1000, "M"}};
