class Solution {
private:
    static const int L;

    std::vector<std::vector<char>> setupBoard(const std::vector<std::vector<int>>& queens,
                                              const std::vector<int>& king)
    {
        std::vector<std::vector<char>> board(L, std::vector<char>(L, ' '));

        for(const auto& queen : queens)
            board[queen[0]][queen[1]] = 'Q';

        board[king[0]][king[1]] = 'K';

        return board;
    }

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        auto board = setupBoard(queens, king);

        std::vector<std::vector<int>> killerQueens;

        // up
        for(int i = king[0] - 1; i >= 0; --i)
            if(board[i][king[1]] == 'Q')
            {
                killerQueens.push_back({i, king[1]});
                break;
            }

        // down
        for(int i = king[0] + 1; i < L; ++i)
            if(board[i][king[1]] == 'Q')
            {
                killerQueens.push_back({i, king[1]});
                break;
            }

        // left
        for(int j = king[1] - 1; j >= 0; --j)
            if(board[king[0]][j] == 'Q')
            {
                killerQueens.push_back({king[0], j});
                break;
            }

        // right
        for(int j = king[1] + 1; j < L; ++j)
            if(board[king[0]][j] == 'Q')
            {
                killerQueens.push_back({king[0], j});
                break;
            }

        // up-left
        for(int i = king[0] - 1, j = king[1] - 1; i >= 0 && j >= 0; --i, --j)
            if(board[i][j] == 'Q')
            {
                killerQueens.push_back({i, j});
                break;
            }

        // up-right
        for(int i = king[0] - 1, j = king[1] + 1; i >= 0 && j < L; --i, ++j)
            if(board[i][j] == 'Q')
            {
                killerQueens.push_back({i, j});
                break;
            }

        // down-left
        for(int i = king[0] + 1, j = king[1] - 1; i < L && j >= 0; ++i, --j)
            if(board[i][j] == 'Q')
            {
                killerQueens.push_back({i, j});
                break;
            }

        // down-right
        for(int i = king[0] + 1, j = king[1] + 1; i < L && j < L; ++i, ++j)
            if(board[i][j] == 'Q')
            {
                killerQueens.push_back({i, j});
                break;
            }

        return killerQueens;
    }
};

const int Solution::L = 8;
