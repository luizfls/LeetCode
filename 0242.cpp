class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<string::value_type, unsigned int> sMap;
        for(const auto& c : s)
            sMap[c]++;
        unordered_map<string::value_type, unsigned int> tMap;
        for(const auto& c : t)
            tMap[c]++;
        return sMap == tMap;
    }
};
