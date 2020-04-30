class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::unordered_set<std::size_t> rows, cols;
        for(std::size_t i = 0u; i < matrix.size(); ++i)
            for(std::size_t j = 0u; j < matrix[i].size(); ++j)
                if(matrix[i][j] == 0)
                {
                    rows.emplace(i);
                    cols.emplace(j);
                }

        for(auto row : rows)
            for(std::size_t j = 0u; j < matrix[row].size(); ++j)
                matrix[row][j] = 0;

        for(auto col : cols)
            for(std::size_t i = 0u; i < matrix.size(); ++i)
                matrix[i][col] = 0;
    }
};
