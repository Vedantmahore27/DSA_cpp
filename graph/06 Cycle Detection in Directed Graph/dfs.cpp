class Solution {
  public:
  bool solve(int Node,vector<int> &visited,vector<int> &path, vector<vector<int>> &adj){
        visited[Node]=1;
        path[Node]=1;
        
        for(int j=0;j<adj[Node].size();j++){
            if(path[adj[Node][j]]==1)return true;
            if(visited[adj[Node][j]])continue;
            if(solve(adj[Node][j] ,visited,path,adj)) return true;
            
        }
        path[Node]=0;
        return 0;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
       //create list first
       vector<vector<int>> adj(V);
       
       for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           
       }
       
       
       //dfs
       vector<int>visited(V,0);
       vector<int> path(V,0);
  
       
       for(int i=0;i<V;i++){
           if(!visited[i])
           if(solve(i,visited,path,adj))return true;
       }
     
       return false;
        
        
    }
};

