class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));

        // {{row, col}, distance/steps}
        queue<pair<pair<int, int>, int>> q;


        // STEP 1: Put all 0s into the queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {

                    // Distance of every 0 from itself is 0
                    q.push({{i, j}, 0});

                    // Mark the 0 as visited
                    vis[i][j] = 1;
                }
            }
        }


        // STEP 2: BFS
        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            // Store the distance for this cell
            distance[row][col] = steps;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m &&
                   ncol >= 0 && ncol < n &&
                   vis[nrow][ncol] == 0) {

                    // Mark the neighbour as visited
                    vis[nrow][ncol] = 1;

                    // Add neighbour to queue
                    // Its distance is current distance + 1
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return distance;
    }
};