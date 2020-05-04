class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};

        std::vector<std::string> combinations{{}};

        for(auto digit : digits)
        {
            auto growthFactor = _keyboard.at(digit).size();

            std::vector<std::string> expandedCombinations;
            for(const auto& combination : combinations)
                expandedCombinations.insert(expandedCombinations.end(), factor, combination);

            int i = 0;
            while(i < expandedCombinations.size())
                for(auto letter : _keyboard.at(digit))
                    expandedCombinations[i++].push_back(letter);

            combinations.swap(expandedCombinations);
        }

        return combinations;
    }

private:
    static const std::unordered_map<char, std::vector<char>> _keyboard;
};

const std::unordered_map<char, std::vector<char>> Solution::_keyboard =
{
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}},
};
