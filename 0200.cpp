class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;

        int nIslands = 0;

        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid.front().size(), false));
        for(std::size_t i = 0; i < grid.size(); ++i)
            for(std::size_t j = 0; j < grid[i].size(); ++j)
                if(grid[i][j] == '1' && !visited[i][j])
                    explore(grid, visited, i, j, nIslands);

        return nIslands;
    }

private:
    void explore(const std::vector<std::vector<char>>& grid,
                 std::vector<std::vector<bool>>& visited,
                 std::size_t i, std::size_t j, int& nIslands)
    {
        std::stack<std::pair<std::size_t, std::size_t>> s({{i, j}});
        while(!s.empty())
        {
            auto [i, j] = s.top();
            s.pop();

            visited[i][j] = true;

            if(i != 0 && !visited[i - 1][j] && grid[i - 1][j] == '1')
                s.push({i - 1, j});
            if(i != grid.size() - 1 && !visited[i + 1][j] && grid[i + 1][j] == '1')
                s.push({i + 1, j});
            if(j != 0 && !visited[i][j - 1] && grid[i][j - 1] == '1')
                s.push({i, j - 1});
            if(j != grid[i].size() - 1 && !visited[i][j + 1] && grid[i][j + 1] == '1')
                s.push({i, j + 1});
        }

        nIslands++;
    }
};
