class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<std::string::value_type, unsigned int> char2freq;
        for(auto c : s)
            ++char2freq[c];

        std::map<unsigned int, std::string, std::greater<unsigned int>> freq2substring;
        for(auto [letter, frequency] : char2freq)
            freq2substring[frequency] += string(frequency, letter);

        std::string result;
        for(const auto& [_, substring] : freq2substring)
            result += substring;
        return result;
    }
};
