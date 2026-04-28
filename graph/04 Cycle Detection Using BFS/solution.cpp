class Solution {
public:
    bool bfs(int start, vector<int>& visited, vector<vector<int>>& adj) {
        queue<pair<int,int>> q; 
        
        visited[start] = 1;
        q.push({start, -1});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int parent = front.second;

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent) {
                    return true; 
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, visited, adj)) return true;
            }
        }

        return false;
    }
};
