class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       
       int n = wt.size();
       int dp[1001][1001];
       for(int i=0;i<n;i++){
           dp[i][0]=0;
           dp[0][i]=0;
       }
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=capacity;j++){
               if(wt[i-1]<=j){
                   dp[i][j]= max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
               }
               else dp[i][j]=dp[i-1][j];
           }
       }
       
       return dp[n][capacity];
        
    }
};
