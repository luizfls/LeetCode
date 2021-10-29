class Solution {
public:
    bool isSubsequence(string S, string T) {
        if(T.size() < S.size()) return false;

        int i = 0;
        for(auto t : T)
        {
            if(i == S.size()) return true;
            if(S[i] == t) ++i;
        }

        return i == S.size();
    }
};
