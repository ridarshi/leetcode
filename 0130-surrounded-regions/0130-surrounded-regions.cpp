
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();       // Number of rows
        int n = board[0].size();    // Number of columns

        // Check the left and right boundary cells
        for (int i = 0; i < m; i++) {
            bfs(board, i, 0);       // Left boundary
            bfs(board, i, n - 1);   // Right boundary
        }

        // Check the top and bottom boundary cells
        for (int j = 0; j < n; j++) {
            bfs(board, 0, j);       // Top boundary
            bfs(board, m - 1, j);   // Bottom boundary
        }

        // Convert the remaining surrounded 'O's to 'X'
        // Restore the boundary-connected cells from '#' to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int row, int col) {
        // If this boundary cell is not 'O', there is nothing to explore
        if (board[row][col] != 'O') {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        // Add the starting cell to the queue
        q.push({row, col});

        // Mark it immediately so it isn't added again
        board[row][col] = '#';

        // Directions: Up, Right, Down, Left
        vector<int> dirx{-1, 0, 1, 0};
        vector<int> diry{0, 1, 0, -1};

        // Continue until all connected cells are explored
        while (!q.empty()) {

            // Get the current cell's coordinates
            int r = q.front().first;
            int c = q.front().second;

            // Remove the current cell from the queue
            q.pop();

            // Explore all four neighboring cells
            for (int i = 0; i < 4; i++) {

                int nr = r + dirx[i];  // Neighbor's row
                int nc = c + diry[i];  // Neighbor's column

                // Check that the neighbor is inside the board
                // and is an unvisited 'O'
                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    board[nr][nc] == 'O') {

                    // Add the neighbor to the queue
                    q.push({nr, nc});

                    // Mark it visited using '#'
                    // IMPORTANT: use =, not ==
                    board[nr][nc] = '#';
                }
            }
        }
    }
};
