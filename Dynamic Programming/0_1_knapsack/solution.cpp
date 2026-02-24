//Approach 3
class Solution {
  public:
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        int dp[n+1][W+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        } 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j){
                    //pick or nonpick
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][W];
        
        
    }
};

//Approach 2

class Solution {
  public:
  
    int solve(int n, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(n==-1 || W==0)return 0;
        
        if(dp[n][W]!=-1) return dp[n][W];
        int pick=0;
        if(wt[n]<=W){
            pick=val[n]+solve(n-1,W-wt[n],val,wt,dp);
        }
        int nonpick= solve(n-1,W,val,wt,dp);
        
        return dp[n][W]=max(pick,nonpick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        if(n==0 || W==0)return 0;
        
        vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
        return solve(n-1,W,val,wt,dp); //n-1 is index
        
    }
};


//Approach 1

class Solution {
  public:
    int solve(int n, int W, vector<int> &val, vector<int> &wt){
        if(n==-1 || W==0)return 0;
        int pick=0;
        if(wt[n]<=W){
            pick=val[n]+solve(n-1,W-wt[n],val,wt);
        }
        int nonpick= solve(n-1,W,val,wt);
        
        return max(pick,nonpick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        if(n==0 || W==0)return 0;
        
        return solve(n-1,W,val,wt); //n-1 is index
        
    }
};
