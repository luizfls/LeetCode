class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        std::vector<int> leftRight(grid.size(), 0);
        std::vector<int> topBottom(grid.size(), 0);

        for(std::size_t i = 0; i < grid.size(); ++i)
        {
            for(std::size_t j = 0; j < grid.size(); ++j)
            {
                leftRight[i] = std::max(leftRight[i], grid[i][j]);
                topBottom[j] = std::max(topBottom[j], grid[i][j]);
            }
        }

        int increase = 0;

        for(std::size_t i = 0; i < grid.size(); ++i)
            for(std::size_t j = 0; j < grid.size(); ++j)
                increase += std::min(leftRight[i], topBottom[j]) - grid[i][j];

        return increase;
    }
};
