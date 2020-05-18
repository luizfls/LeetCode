class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty())
            return {};
        else if(B.empty())
            return {};

        std::vector<std::vector<int>> intervals;

        auto ait = A.begin();
        auto bit = B.begin();

        while(ait != A.end() && bit != B.end())
        {
            // no intersection
            if((*ait)[1] < (*bit)[0])
                ++ait;
            else if((*bit)[1] < (*ait)[0])
                ++bit;
            else
            {
                // define intersection
                auto start = std::max((*ait)[0], (*bit)[0]);
                auto close = std::min((*ait)[1], (*bit)[1]);

                intervals.push_back({start, close});

                // update iterator
                if((*ait)[1] == (*bit)[1])
                {
                    ++ait;
                    ++bit;
                }
                else if((*ait)[1] < (*bit)[1])
                    ++ait;
                else if((*bit)[1] < (*ait)[1])
                    ++bit;
            }
        }

        return intervals;
    }
};
