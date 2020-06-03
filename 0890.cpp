class Solution {
private:
    std::vector<int> normalize(const std::string& word)
    {
        std::vector<int> normalized;

        int code = 1;
        std::unordered_map<char, int> char2code;
        for(auto c : word)
        {
            if(char2code[c] == 0)
                char2code[c] = code++;
            normalized.emplace_back(char2code[c]);
        }

        return normalized;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto normalizedPattern = normalize(pattern);

        std::vector<std::string> wordsInPattern;

        for(const auto& word : words)
            if(normalize(word) == normalizedPattern)
                wordsInPattern.emplace_back(word);

        return wordsInPattern;
    }
};
