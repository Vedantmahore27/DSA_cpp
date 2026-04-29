class Solution {
  public:
  
    bool solve(int node, vector<int> &color, vector<vector<int>> &adj){
        
        for(int j = 0; j < adj[node].size(); j++){
            
            if(color[adj[node][j]] == -1){
                color[adj[node][j]] = !color[node];
                
                if(!solve(adj[node][j], color, adj)) return false;
            }
            else{
                if(color[adj[node][j]] == color[node]) return false;
            }
        }
        
        return true;
    }
    
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        
        // build undirected graph
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        // handle disconnected graph
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                color[i] = 0;
                
                if(!solve(i, color, adj)) return false;
            }
        }
        
        return true;
    }
};
