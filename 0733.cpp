class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        auto oldColor = image[sr][sc];

        if(oldColor == newColor)
            return image;

        const int h = image.size();
        const int w = image.front().size();

        std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
        std::queue<std::pair<int, int>> q({{sr, sc}});
        while(!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            image[i][j] = newColor;
            visited[i][j] = true;

            if(i > 0 && !visited[i - 1][j] && image[i - 1][j] == oldColor)
                q.push({i - 1, j});
            if(i < h - 1 && !visited[i + 1][j] && image[i + 1][j] == oldColor)
                q.push({i + 1, j});
            if(j > 0 && !visited[i][j - 1] && image[i][j - 1] == oldColor)
                q.push({i, j - 1});
            if(j < w - 1 && !visited[i][j + 1] && image[i][j + 1] == oldColor)
                q.push({i, j + 1});
        }

        return image;
    }
};
