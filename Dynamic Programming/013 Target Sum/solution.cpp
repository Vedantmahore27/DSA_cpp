class Solution {
public:
    int subset_sum(vector<int> nums, int target) {
        if(target<0) return 0;
        int n = nums.size();
        int dp[n + 1][target + 1];
        

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
               if(j==0)dp[i][j]=1;
               else if(i==0)dp[i][j]=0;
               
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       
        int sum = accumulate(nums.begin(), nums.end(), 0);


        if ((sum + target) % 2 != 0 || (sum + target) < 0) return 0;

        int s1 = (sum + target) / 2;
        return subset_sum(nums, s1);
         
    }
};
