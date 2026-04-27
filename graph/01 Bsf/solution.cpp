class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
       int n = adj.size();
       queue<int> q;
       vector<int> visited(n,-1);
       vector<int> ans;
       
       q.push(0);
       visited[0]=1;
       
       while(!q.empty()){
           
           for(int i=0;i<adj[q.front()].size();i++){
               if(visited[adj[q.front()][i]]==-1){
                   q.push(adj[q.front()][i]);
                   visited[adj[q.front()][i]]=1;
               }
           }
                  
           ans.push_back(q.front());
           q.pop();
           }
         
       
       
       return ans;
    }
};
