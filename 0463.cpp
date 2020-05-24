class Solution {
private:
    int getCellPerimeter(const std::vector<std::vector<int>>& grid, std::size_t i, std::size_t j)
    {
        int cp = 0;

        if(i == 0 || grid[i - 1][j] == 0)
            ++cp;
        if(i == grid.size() - 1 || grid[i + 1][j] == 0)
            ++cp;
        if(j == 0 || grid[i][j - 1] == 0)
            ++cp;
        if(j == grid[i].size() - 1 || grid[i][j + 1] == 0)
            ++cp;

        return cp;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ip = 0;

        for(std::size_t i = 0; i < grid.size(); ++i)
            for(std::size_t j = 0; j < grid[i].size(); ++j)
                if(grid[i][j] == 1)
                    ip += getCellPerimeter(grid, i , j);

        return ip;
    }
};
