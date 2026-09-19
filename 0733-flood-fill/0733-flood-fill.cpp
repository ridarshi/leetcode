class Solution {
public:

    // DFS function to visit all connected cells
    // having the same original color
    void dfs(int sr, int sc, int &inicolor, int &color,
             vector<vector<int>>& ans) {

        int m = ans.size();       // Number of rows
        int n = ans[0].size();    // Number of columns

        // Change the current cell to the new color
        ans[sr][sc] = color;

        // Directions for moving:
        //      Up
        // Left   Right
        //      Down
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Check all 4 neighbouring cells
        for (int i = 0; i < 4; i++) {

            // Calculate the neighbour's row and column
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            // Check if the neighbour is inside the grid
            // AND has the original color
            // AND is not already the new color
            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                ans[nrow][ncol] == inicolor &&
                ans[nrow][ncol] != color) {

                // Recursively perform DFS on that neighbour
                dfs(nrow, ncol, inicolor, color, ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        // Make a copy of the original image
        // so that we don't modify the input directly
        vector<vector<int>> ans = image;

        // Store the original color of the starting cell
        int inicolor = image[sr][sc];

        // Start DFS from the given starting cell
        dfs(sr, sc, inicolor, color, ans);

        // Return the modified image
        return ans;
    }
};