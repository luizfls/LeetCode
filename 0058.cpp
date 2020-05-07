class Solution {
public:
    int lengthOfLastWord(string s) {
        auto lastLetter = s.find_last_not_of(' ');
        auto rightTrim = s.substr(0, lastLetter + 1);
        auto firstSpaceBeforeLastLetter = rightTrim.find_last_of(' ');
        return firstSpaceBeforeLastLetter != std::string::npos
                   ? rightTrim.size() - firstSpaceBeforeLastLetter - 1
                   : lastLetter + 1;
    }
};
