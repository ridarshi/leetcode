class Solution {
private:

    // BFS function to visit all the connected '1's
    // starting from (row, col)
    void bfs(int row, int col,
             vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        // Number of rows and columns
        int m = grid.size();
        int n = grid[0].size();

        // Queue stores coordinates: {row, col}
        queue<pair<int, int>> q;

        // Put the starting cell into the queue
        q.push({row, col});

        // Mark starting cell as visited
        vis[row][col] = 1;

        // Continue BFS until queue becomes empty
        while (!q.empty()) {

            // Get the row and column of the front cell
            int r = q.front().first;
            int c = q.front().second;

            // Remove the front cell from the queue
            q.pop();

            // Directions:
            //        UP    RIGHT  DOWN  LEFT
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            // Check all 4 neighboring cells
            for (int i = 0; i < 4; i++) {

                // Calculate the neighbor's coordinates
                int neig_row = r + drow[i];
                int neig_col = c + dcol[i];

                // Check whether the neighbor:
                // 1. Is inside the grid
                // 2. Is land ('1')
                // 3. Has not been visited yet
                if (neig_row >= 0 && neig_row < m &&
                    neig_col >= 0 && neig_col < n &&
                    grid[neig_row][neig_col] == '1' &&
                    vis[neig_row][neig_col] == 0) {

                    // Mark the neighbor as visited
                    vis[neig_row][neig_col] = 1;

                    // Add the neighbor to the queue
                    q.push({neig_row, neig_col});
                }
            }
        }
    }


public:

    int numIslands(vector<vector<char>>& grid) {

        // Number of rows and columns
        int m = grid.size();
        int n = grid[0].size();

        // visited matrix
        // 0 = not visited
        // 1 = visited
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Stores the number of islands
        int cnt = 0;

        // Traverse every cell of the grid
        for (int row = 0; row < m; row++) {

            for (int col = 0; col < n; col++) {

                // If we find land ('1') that has not been visited,
                // we have found a NEW island
                if (!vis[row][col] && grid[row][col] == '1') {

                    // Increase island count
                    cnt++;

                    // BFS will visit the entire connected island
                    bfs(row, col, vis, grid);
                }
            }
        }

        // Return total number of islands
        return cnt;
    }
};