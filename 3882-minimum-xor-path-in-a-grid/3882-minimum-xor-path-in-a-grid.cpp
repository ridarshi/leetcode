class Solution {
public:
    int ans = INT_MAX;

    vector<vector<vector<bool>>> visited;

    void dfs(int i, int j, int xorVal, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        xorVal ^= grid[i][j];

        // Skip only if this exact state was already explored
        if (visited[i][j][xorVal]) {
            return;
        }

        visited[i][j][xorVal] = true;

        // Update the answer only after reaching the destination
        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xorVal);
            return;
        }

        if (i + 1 < m) {
            dfs(i + 1, j, xorVal, grid);
        }

        if (j + 1 < n) {
            dfs(i, j + 1, xorVal, grid);
        }
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        visited.assign(m, vector<vector<bool>>(n, vector<bool>(1024, false)));

        dfs(0, 0, 0, grid);

        return ans;
    }
};