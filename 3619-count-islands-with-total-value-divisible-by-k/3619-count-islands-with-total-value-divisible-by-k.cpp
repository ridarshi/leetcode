
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        // Initially, all cells are unvisited
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Start BFS for each unvisited non-zero cell
                if (grid[i][j] != 0 && !visit[i][j] &&
                    bfs(k, i, j, grid, visit)) {
                    count++;
                }
            }
        }

        return count;
    }

    bool bfs(int& k, int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& visit) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Add the starting cell to the queue
        q.push({i, j});

        // Mark the starting cell as visited
        visit[i][j] = true;

        // Store the sum of all cells in this connected island
        long long sum = grid[i][j];

        // Directions: Up, Right, Down, Left
        vector<int> dirx{-1, 0, 1, 0};
        vector<int> diry{0, 1, 0, -1};

        while (!q.empty()) {

            // Get the current cell
            int x = q.front().first;
            int y = q.front().second;

            // Remove the current cell from the queue
            q.pop();

            // Explore all four neighboring cells
            for (int d = 0; d < 4; d++) {
                int r = x + dirx[d];
                int c = y + diry[d];

                // Check bounds, non-zero value, and visited status
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 0 &&
                    !visit[r][c]) {

                    // Add the neighbor's value to the island sum
                    sum += grid[r][c];

                    // Add the neighbor to the queue
                    q.push({r, c});

                    // IMPORTANT: mark visited immediately
                    visit[r][c] = true;
                }
            }
        }

        // An island is valid if its total sum is divisible by k
        return sum % k == 0;
    }
};
