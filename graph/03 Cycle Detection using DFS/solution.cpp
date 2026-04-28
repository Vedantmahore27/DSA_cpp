class Solution {
  public:
    bool solve(int Node, int parent ,vector<int> &visited, vector<vector<int>> &adj){
        visited[Node]=1;
        for(int j=0;j<adj[Node].size();j++){
            if(parent==adj[Node][j])continue;
            if(visited[adj[Node][j]])return true;
            if(solve(adj[Node][j],Node ,visited,adj)) return true;
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
       
       //create list first
       vector<vector<int>> adj(V);
       
       for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
       
       
       //dfs
       vector<int>visited(V,0);
       bool ans;
       for(int i=0;i<V;i++){
           if(!visited[i])
           ans = ans || solve(i,-1,visited,adj);
       }
     
       return ans;
        
    }
};
