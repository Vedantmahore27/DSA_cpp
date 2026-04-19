//Approach 3
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
         int n = arr.size();
        int dp[n+1][sum+1];
       
        for(int i=0 ; i<=sum;i++){
            dp[0][i]=false;
        }
        
        for(int i=0 ; i<=n;i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                if(arr[i-1]<=j){
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
        
    }
};


//APPROACH2 @ memoize

class Solution {
  public:
    bool solve(vector<int> & arr , int sum , int n, int dp[][1001]){
        if(n==-1){
            if(sum==0)return true;
            else return false;
        }
        if(sum==0)return true;
        if(dp[n][sum]!=-1)return dp[n][sum];
        //pick
        bool pick=false;
        if(arr[n]<=sum)
         pick =solve(arr,sum-arr[n],n-1,dp);
        
        bool nonpick =solve(arr,sum,n-1,dp);
        
        return dp[n][sum]= pick ||nonpick;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return solve(arr,sum,n-1,dp);
        
    }
};

//Approach 1
class Solution {
  public:
    bool solve(vector<int> & arr , int sum , int n){
        if(n==-1){
            if(sum==0)return true;
            else return false;
        }
        if(sum==0)return true;
        
        //pick
        bool pick=false;
        if(arr[n]<=sum)
         pick =solve(arr,sum-arr[n],n-1);
        
        bool nonpick =solve(arr,sum,n-1);
        
        return pick ||nonpick;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(arr,sum,n-1);
        
    }
};
