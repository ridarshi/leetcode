class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            bfs(board, i, 0);
            bfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            bfs(board, 0, j);
            bfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] != 'O') {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

        board[row][col] = '#';

        vector<int> dirx{-1, 0, 1, 0};
        vector<int> diry{0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dirx[i];
                int nc = c + diry[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    board[nr][nc] == 'O') {
                    q.push({nr, nc});
                    board[nr][nc] = '#';
                }
            }
        }
    }
};