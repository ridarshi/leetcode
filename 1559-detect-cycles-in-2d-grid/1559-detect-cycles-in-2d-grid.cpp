class Solution {
public:
    // BFS function to detect a cycle starting from (i, j)
    bool detect(int i, int j, vector<vector<bool>>& vis,
                vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Mark the starting cell as visited
        vis[i][j] = true;

        // Store:
        // {current row, current col, parent row, parent col}
        queue<array<int, 4>> q;

        // Starting cell has no parent
        q.push({i, j, -1, -1});

        while (!q.empty()) {

            // Get current cell and its parent
            auto [row, col, parentrow, parentcol] = q.front();
            q.pop();

            // Directions: up, right, down, left
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            // Check all 4 neighbours
            for (int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check:
                // 1. Neighbour is inside the grid
                // 2. Neighbour has the same character
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == grid[row][col]) {

                    // If neighbour is not visited,
                    // visit it and store current cell as its parent
                    if (!vis[nrow][ncol]) {

                        vis[nrow][ncol] = true;

                        q.push({nrow, ncol, row, col});
                    }

                    // If neighbour is already visited and
                    // it is NOT the parent, then a cycle exists
                    else if (nrow != parentrow || ncol != parentcol) {

                        return true;
                    }
                }
            }
        }

        // No cycle found in this connected component
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Initially, no cell has been visited
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Check every cell because the grid can have
        // multiple disconnected components
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Start BFS only from an unvisited cell
                if (!vis[i][j]) {

                    // If BFS finds a cycle, return true
                    if (detect(i, j, vis, grid)) {
                        return true;
                    }
                }
            }
        }

        // No cycle exists anywhere in the grid
        return false;
    }
};
