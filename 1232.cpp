class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // test for two points
        if(coordinates.size() == 2)
            return true;

        using Point = std::vector<int>;
        auto cmp = [](const Point& p1, const Point& p2)
                   {
                       if(p1[0] == p2[0])
                           return p1[1] < p2[1];

                       return p1[0] < p2[0];
                   };
        std::sort(coordinates.begin(), coordinates.end(), cmp);

        auto ref_dx = coordinates[1][0] - coordinates[0][0];
        auto ref_dy = coordinates[1][1] - coordinates[0][1];

        // test vertical line
        if(ref_dx == 0)
        {
            for(const auto& point : coordinates)
                if(point[0] != coordinates[0][0])
                    return false;
            return true;
        }

        for(std::size_t i = 2; i < coordinates.size(); ++i)
        {
            auto curr_dx = coordinates[i][0] - coordinates[i - 1][0];

            auto dy_goal = curr_dx * ref_dy / ref_dx;
            auto curr_dy = coordinates[i][1] - coordinates[i - 1][1];

            if(curr_dy != dy_goal)
                return false;
        }

        return true;
    }
};
