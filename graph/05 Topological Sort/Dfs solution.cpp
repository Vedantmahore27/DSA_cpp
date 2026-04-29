class Solution {
  public:
    bool solve(int Node,vector<int> &ans,vector<int> &visited , vector<vector<int>> & adj){
        
        visited[Node]=1;
        
        for(int i=0;i<adj[Node].size();i++){
            
            if(visited[adj[Node][i]]==-1){
               solve(adj[Node][i],ans,visited,adj);
            }
        
        }
            ans.push_back(Node);
     
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visited(V,-1);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(visited[i]==-1){
              solve(i,ans,visited,adj);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
