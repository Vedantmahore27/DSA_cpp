class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        vector<int> color(V,-1);
        queue<int> q;
       
        
        for(int i=0;i<V;i++){
        if(color[i]!=-1)continue;
        q.push(i);
        color[i]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int i=0;i<adj[node].size();i++){
                if(color[adj[node][i]]==-1){
                    color[adj[node][i]]=!color[node];
                    q.push(adj[node][i]);
                }
                else{
                    if(color[adj[node][i]]==color[node])return false;
                }
            }
        }
        
      }
        
        return true;
        
    }
};
