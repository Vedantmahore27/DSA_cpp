//approach 1
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int dp[1001][1001];
        int n=arr.size();
        for(int i=0;i<=target;i++){
             dp[0][i]=0;
        }
       dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                
                if(arr[i-1]<=j){
                    dp[i][j]= dp[i-1][j-arr[i-1]]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};

//need to understand for Approach 2 
| Style | Start Call   | Answer            |
|-------|--------------|-------------------|
| Index | solve(n-1)   | dp[n-1][target]   |
| Size  | solve(n)     | dp[n][target]     |

//Approach 2 - Memoization
//size based approach
class Solution {
  public:
    int solve(vector<int> &arr, int target, int n, int dp[][1001]){
        
        if(n == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if(dp[n][target] != -1) return dp[n][target];

        int pick = 0;
        if(arr[n-1] <= target){
            pick = solve(arr, target - arr[n-1], n-1, dp);
        }

        int nonpick = solve(arr, target, n-1, dp);

        return dp[n][target] = pick + nonpick;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        
        return solve(arr, target, n, dp);   // start from size
    }
};

//index based approach
class Solution {
  public:
    int solve(vector<int> &arr, int target, int n, int dp[][1001]){
        
        if(n == -1){
            return (target == 0);
        }

        if(dp[n][target] != -1) return dp[n][target];

        int pick = 0;
        if(arr[n] <= target){
            pick = solve(arr, target - arr[n], n-1, dp);
        }

        int nonpick = solve(arr, target, n-1, dp);

        return dp[n][target] = pick + nonpick;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        
        return solve(arr, target, n-1, dp);   // start from last index
    }
};


//Approach 1
class Solution {
  public:
    int  solve(vector<int> & arr,int target,int n){
        if(n==-1){
            if(target==0)return 1;
            else return 0;
        }
        
        int pick=0;
        if(arr[n]<=target){
          pick = solve(arr,target-arr[n],n-1);
        }
        int nonpick =solve(arr,target,n-1);
        
        return pick+nonpick;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        int n =arr.size();
       
        return solve(arr,target,n-1);
    }
};
