
class Solution {

  public:
 int count_subset(vector<int>& arr, int target){
        int n = arr.size();
        int dp[n+1][target+1];

        // base cases
        for(int j = 0; j <= target; j++){
            dp[0][j] = 0;
        }
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){

                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }

  int countPartitions(vector<int>& arr, int d) {
      int n = arr.size();
      int sum = 0;
      for (int i = 0; i < n; i++) {
          sum += arr[i];
      }

      if ((sum + d) % 2 != 0 || d > sum) return 0;

      int s1 = (d + sum) / 2;
      return count_subset(arr, s1);
  }
};



