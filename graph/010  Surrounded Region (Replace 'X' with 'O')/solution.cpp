class Solution {
  public:
  
    int r,c;
    int row[4] ={-1,0,1,0};
    int col[4]= {0,1,0,-1};
    bool valid(int i ,int j ){
        return i>=0 && j>=0 && i<r && j<c;
    }
    
    void fill(vector<vector<char>>& grid) {
        // Code here
         r = grid.size();
         c = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0;i<c;i++){
            if(grid[0][i]=='O'){
                q.push({0,i});
                grid[0][i]='T';
        }
      }
        
        for(int i=0;i<r;i++){
            if(grid[i][0]=='O'){
                q.push({i,0});
                grid[i][0]='T';
        }
    }
        
        for(int i=1;i<c;i++){
            if(grid[r-1][i]=='O'){
                q.push({r-1,i});
                grid[r-1][i]='T';
            }
        }
        
        for(int i=1;i<r-1;i++){
            if(grid[i][c-1]=='O'){
                grid[i][c-1]='T';
                 q.push({i,c-1});
            }
        }
        
        while(!q.empty()){
            int ni= q.front().first;
            int nj= q.front().second;
            q.pop();
            for(int k=0;k<4 ;k++){
                if(valid(ni+row[k] ,nj+col[k])  && grid[ni+row[k]][nj+col[k]]=='O'){
                    grid[ni+row[k]][nj+col[k]]='T';
                    q.push({ni+row[k],nj+col[k]});
                }
            }
            
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='T')grid[i][j]='O';
                else grid[i][j]='X';
            }
        }
        
    }
};
