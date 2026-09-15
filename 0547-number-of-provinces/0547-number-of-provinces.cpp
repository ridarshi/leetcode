class Solution {
public:

    // DFS to visit all cities belonging to the same province
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adjLs) {

        // Mark current city as visited
        vis[node] = true;

        // Visit all connected cities
        for (int it : adjLs[node]) {

            if (vis[it] == false) {
                dfs(it, vis, adjLs);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int v = isConnected.size();

        // Create adjacency list
        vector<vector<int>> adjLs(v);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < v; i++) {

            for (int j = 0; j < v; j++) {

                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                }
            }
        }

        // Initially no city is visited
        vector<bool> vis(v, false);

        int provinces = 0;

        // Find every unvisited connected component
        for (int i = 0; i < v; i++) {

            if (vis[i] == false) {

                // Found a new province
                provinces++;

                // Visit the complete province
                dfs(i, vis, adjLs);
            }
        }

        return provinces;
    }
};