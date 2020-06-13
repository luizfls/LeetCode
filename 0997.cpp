class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        std::vector<int> trustees(N + 1, 0);
        int judge = 1;

        for(const auto& t : trust)
            if(++trustees[t[1]] > trustees[judge])
                judge = t[1];

        // everybody trusts the town judge, except himself
        if(trustees[judge] != N - 1)
            return -1;

        // there is only one town judge
        if(std::count(std::next(trustees.begin()), trustees.end(), trustees[judge]) > 1)
            return -1;

        // town judge trusts nobody
        for(const auto& t : trust)
            if(t[0] == judge)
                return -1;

        return judge;
    }
};
