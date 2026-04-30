class Solution {
public:
    int r,c;
    int row[4] ={-1,0,1,0};
    int col[4]= {0,1,0,-1};
    bool valid(int i ,int j ){
        return i>=0 && j>=0 && i<r && j<c;
    }

    int numIslands(vector<vector<char>>& grid) {
        r=grid.size();
        c=grid[0].size();
        int island =0;

        queue<pair<int,int>> q;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
              
              if(grid[i][j]=='1'){ // i found land
                    island++;
                    q.push({i,j});
                    grid[i][j]='0';       // without creating an another array of visited insted we can gave 0 to them


                    while(!q.empty()){
                       int ni =q.front().first;
                       int nj =q.front().second;
                       q.pop();

                       for(int k=0;k<4;k++){
                        if(valid(ni+row[k],nj+col[k]) && grid[ni+row[k]][nj+col[k]]=='1'){
                            grid[ni+row[k]][nj+col[k]]='0';
                            q.push({ni+row[k],nj+col[k]});
                        }
                       }
                    }
                }
            }
        }
        return island;
    }
};
