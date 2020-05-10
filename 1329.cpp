class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const auto m = mat.size();
        const auto n = mat.front().size();

        // Isolate diagonals
        std::vector<std::vector<int>> diagonals;
        diagonals.reserve(m + n - 1);

        for(int i_ = m - 1; i_ >= 0; --i_)
        {
            diagonals.emplace_back(std::vector<int>{});
            for(auto [i, j] = std::pair{i_, 0}; i < m && j < n; ++i, ++j)
                diagonals.back().emplace_back(mat[i][j]);
        }

        for(int j_ = 1; j_ < n; ++j_)
        {
            diagonals.emplace_back(std::vector<int>{});
            for(auto [i, j] = std::pair{0, j_}; i < m && j < n; ++i, ++j)
                diagonals.back().emplace_back(mat[i][j]);
        }

        // Sort each diagonal
        for(auto& diagonal : diagonals)
            std::sort(diagonal.begin(), diagonal.end());

        // Flatten diagonals into single buffer
        std::vector<int> diagonalsFlat;
        diagonalsFlat.reserve(m * n);
        for(const auto& diagonal : diagonals)
            diagonalsFlat.insert(diagonalsFlat.end(), diagonal.begin(), diagonal.end());

        // Build diagonally sorted matrix
        std::vector<std::vector<int>> diagonalMat(m, std::vector<int>(n));

        auto it = diagonalsFlat.begin();

        for(int i_ = m - 1; i_ >= 0; --i_)
            for(auto [i, j] = std::pair{i_, 0}; i < m && j < n; ++i, ++j)
                diagonalMat[i][j] = *it++;

        for(int j_ = 1; j_ < n; ++j_)
            for(auto [i, j] = std::pair{0, j_}; i < m && j < n; ++i, ++j)
                diagonalMat[i][j] = *it++;

        return diagonalMat;
    }
};
