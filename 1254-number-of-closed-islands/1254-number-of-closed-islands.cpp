
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        vector<vector<bool>> visit(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Start BFS only if:
                // 1. The cell is land (0)
                // 2. The cell has not been visited
                // 3. BFS confirms that the island is closed
                if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, grid, visit)) {
                    count++;
                }
            }
        }

        return count;
    }

    bool bfs(int x, int y, vector<vector<int>>& grid,
             vector<vector<bool>>& visit) {

        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        queue<pair<int, int>> q;

        // Add the starting cell to the queue
        q.push({x, y});

        // Mark it visited immediately to avoid adding it again
        visit[x][y] = true;

        // Assume the island is closed until we find otherwise
        bool isclosed = true;

        // Directions: Up, Right, Down, Left
        vector<int> dirx{-1, 0, 1, 0};
        vector<int> diry{0, 1, 0, -1};

        // Continue BFS until there are no cells left to process
        while (!q.empty()) {

            // Get the row and column of the current cell
            x = q.front().first;
            y = q.front().second;

            // Remove the current cell from the queue
            q.pop();

            // Check all four neighboring cells
            for (int i = 0; i < 4; i++) {

                // Calculate the neighboring cell's coordinates
                int r = x + dirx[i]; // New row
                int c = y + diry[i]; // New column

                // If the neighbor is outside the grid,
                // this island touches the boundary.
                // Therefore, it is NOT a closed island.
                if (r < 0 || r >= n || c < 0 || c >= m) {
                    isclosed = false;
                }

                // Otherwise, check whether the neighbor is
                // unvisited land
                else if (grid[r][c] == 0 && !visit[r][c]) {

                    // Add the neighboring land cell to the queue
                    q.push({r, c});

                    // Mark it visited immediately
                    visit[r][c] = true;
                }
            }
        }

        // Return true if the island never touched the boundary
        return isclosed;
    }
};
