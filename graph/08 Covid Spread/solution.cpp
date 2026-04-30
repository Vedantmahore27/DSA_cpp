// User function Template for C++

class Solution {
  public:
  
    int row[4] ={-1,1,0,0};
    int col[4] ={0,0,1,-1};
    
    int r,c;
    
    bool valid(int i,int j){
        return i>=0 && j>=0 && i<r && j<c;
    }
    
    
    
    int helpaterp(vector<vector<int>> hospital) {
       r= hospital.size();
       c=hospital[0].size();
       
       queue<pair<int,int>> q;
       int timer=0;
       int curr_patient=0;
   
       
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
              if(hospital[i][j]==2){
                  q.push({i,j});
                  curr_patient++;
           }
         }
       }
           
       if(curr_patient==0)return 0;
       
       while(!q.empty()){
           
            timer++;
           
            curr_patient = q.size();
        
           
           while(curr_patient--){
               int new_i = q.front().first;
               int new_j = q.front().second;
               q.pop();
               
               for(int k=0;k<4;k++){
                   if(valid(new_i+row[k],new_j+col[k]) && hospital[new_i+row[k]][new_j+col[k]]==1){
                       hospital[new_i+row[k]][new_j+col[k]]=2;
                       q.push({new_i+row[k],new_j+col[k]});
                   }
               }
               
               
           }
       }
       
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++)
            if(hospital[i][j]==1)return -1;
       }
        
        
        return timer-1;
    }
};
