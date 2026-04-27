class Solution {
  public:
    void solve( int node,vector<int>& ans,vector<int> &visited,vector<vector<int>>& adj){
        visited[node]=1;
        ans.push_back(node);
        
        for(int i=0;i< adj[node].size();i++){
            if(!visited[adj[node][i]])solve(adj[node][i],ans,visited,adj);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
         vector<int> ans;
         vector<int> visited(n,0);
         solve(0,ans,visited,adj);
        return ans;
    }
};
