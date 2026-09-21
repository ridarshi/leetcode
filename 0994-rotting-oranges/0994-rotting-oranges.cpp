class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Count the total number of fresh oranges
        int cntfresh = 0;

        // Queue stores:
        // {{row, column}, time}
        // The time tells us after how many minutes that particular orange becomes rotten.
        queue<pair<pair<int, int>, int>> q;

        // visited[i][j] = 2 means this orange has been processed / has become rotten.
        int visited[m][n];

        // Traverse the entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If the orange is already rotten
                if (grid[i][j] == 2) {

                    // Put it into the queue with time = 0
                    q.push({{i, j}, 0});

                    // Mark it as visited
                    visited[i][j] = 2;

                } else {
                    // Empty or fresh cells are initially unvisited
                    visited[i][j] = 0;
                }

                // Count all fresh oranges
                if (grid[i][j] == 1) {
                    cntfresh++;
                }
            }
        }

        // Stores the maximum time taken for rotting
        int time = 0;

        // Counts how many fresh oranges became rotten
        int cnt = 0;

        // Four possible directions:
        //       Up
        // Left  Current  Right
        //       Down
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {

            // Get the current orange's row
            int r = q.front().first.first;

            // Get the current orange's column
            int c = q.front().first.second;

            // Get the time at which this orange became rotten
            int t = q.front().second;

            // Remove the orange from the queue
            q.pop();

            // Keep track of the maximum time
            time = max(time, t);

            // Check all 4 neighbouring cells
            for (int i = 0; i < 4; i++) {

                // Calculate neighbour's row and column
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                // Check:
                // 1. Neighbour is inside the grid
                // 2. Neighbour is a fresh orange
                // 3. Neighbour has not already been visited
                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 &&
                    visited[nrow][ncol] != 2) {

                    // This fresh orange becomes rotten
                    // after one more minute
                    q.push({{nrow, ncol}, time + 1});

                    // Mark it as visited
                    visited[nrow][ncol] = 2;

                    // Increase the count of rotten fresh oranges
                    cnt++;
                }
            }
        }

        // If some fresh oranges could not be reached,
        // they can never become rotten
        if (cnt != cntfresh) {
            return -1;
        }

        // Return the total time required
        return time;
    }
};