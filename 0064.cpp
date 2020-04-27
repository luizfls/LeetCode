class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        _minimals.assign(grid.size(), std::vector<int>(grid.front().size()));

        return minPathSum(grid, 0, 0);
    }

    int minPathSum(const vector<vector<int>>& grid, int i, int j) {
        // invalid position
        if(i == grid.size() || j == grid.front().size())
            return 0;

        // recursive call rightwards, if top row or rightmost column
        auto right = (i == 0 || j == grid.front().size() - 1)
                         ? minPathSum(grid, i, j + 1)
                         : _minimals[i][j + 1];

        // recursive call downwards
        auto down = minPathSum(grid, i + 1, j);

        // bottom row accumulates from the right
        if(i == grid.size() - 1)
            _minimals[i][j] = grid[i][j] + right;
        // rightmost column accumulates from below
        else if(j == grid.front().size() - 1)
            _minimals[i][j] = grid[i][j] + down;
        // other cells accumulate from minimum between right and down
        else
            _minimals[i][j] = grid[i][j] + std::min(right, down);

        return _minimals[i][j];
    }

private:
    // grid with minimal path sums
    std::vector<std::vector<int>> _minimals;
};
