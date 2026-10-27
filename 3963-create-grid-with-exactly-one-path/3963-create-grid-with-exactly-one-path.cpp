class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m, string(n, '#'));

        for(int i = 0;i<n;i++){
            grid[0][i] = '.';
        }

        for(int j = 0;j<m;j++){
            grid[j][n-1] = '.';
        }

        return grid;
    }
};


// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {
//         vector<string> grid(m);
//         grid[0] = string(n, '.');
//         string row = string(n - 1, '#') + '.';

//         for (int i = 1; i < m; i++) {
//             grid[i] = row;
//         }
//         return grid;
//     }
// };