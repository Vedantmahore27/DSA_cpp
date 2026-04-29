class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        vector<int> ans;
        //creating adjacency list
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        //calculating indgree
        
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        
               
     while(!q.empty()){
            int node = q.front();
            q.pop();
               ans.push_back(node);
            
            
            for(int i=0;i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                 
                }
            }
            
        }
        
       
        
        return ans;
    }
};
