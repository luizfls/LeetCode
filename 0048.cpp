class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const auto n = matrix.size();
        auto rot = matrix;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                rot[j][n - i - 1] = matrix[i][j];

        matrix.swap(rot);
    }
};
