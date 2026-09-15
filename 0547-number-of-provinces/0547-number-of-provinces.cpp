// DFS solution
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




// BFS SOLUTION:
// class Solution {
// public:

//     // BFS to visit all cities belonging to the same province
//     void dfs(int node, vector<bool>& vis, vector<vector<int>>& adjLs) {

//         // Create a queue for BFS
//         queue<int> q;

//         // Start BFS from the current city
//         q.push(node);

//         // Mark the starting city as visited
//         vis[node] = true;

//         // Continue until the queue becomes empty
//         while (!q.empty()) {

//             // Take the front city from the queue
//             node = q.front();
//             q.pop();

//             // Visit all cities directly connected to the current city
//             for (int it : adjLs[node]) {

//                 // If the connected city is not visited yet
//                 if (!vis[it]) {

//                     // Add it to the queue for further exploration
//                     q.push(it);

//                     // Mark it as visited
//                     vis[it] = true;
//                 }
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {

//         // Number of cities
//         int v = isConnected.size();

//         // Create an empty adjacency list for all cities
//         vector<vector<int>> adjLs(v);

//         // Convert the given adjacency matrix into an adjacency list
//         for (int i = 0; i < v; i++) {

//             for (int j = 0; j < v; j++) {

//                 // If city i and city j are directly connected
//                 // i != j avoids adding the city itself
//                 if (isConnected[i][j] == 1 && i != j) {

//                     // Add city j to the neighbors of city i
//                     adjLs[i].push_back(j);
//                 }
//             }
//         }

//         // Initially, no city has been visited
//         vector<bool> vis(v, false);

//         // Stores the total number of provinces
//         int provinces = 0;

//         // Check every city
//         for (int i = 0; i < v; i++) {

//             // If this city has not been visited,
//             // it belongs to a new province
//             if (vis[i] == false) {

//                 // We found a new province
//                 provinces++;

//                 // Visit all cities connected to this city
//                 // using BFS
//                 dfs(i, vis, adjLs);
//             }
//         }

//         // Return the total number of provinces
//         return provinces;
//     }
// };
