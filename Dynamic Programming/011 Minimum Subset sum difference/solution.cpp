class Solution {
  public:
    int minDifference(vector<int>& nums) {

        int n = nums.size();
        int range = accumulate(nums.begin(), nums.end(), 0);

       vector<vector<int>> dp(n+1, vector<int>(range+1, 0));

        dp[0][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= range; j++){
                
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        int mini = INT_MAX;

        for(int j = 0; j <= range/2; j++){
            if(dp[n][j]){
                mini = min(mini, range - 2*j);
            }
        }

        return mini;
    }
};
