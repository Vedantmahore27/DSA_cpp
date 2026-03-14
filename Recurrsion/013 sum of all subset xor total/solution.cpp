class Solution {
public:
   int sum=0;
   int z=0;
    void solve(int n , int i , vector<int> &nums){
        if(i==n){
            sum+=z;
            return;
        }
         z = z^ nums[i];
        solve(n,i+1,nums);
        z=z^nums[i];
        solve(n,i+1,nums);
        
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
      
         solve(n,0,nums);
        return sum;
    }
};
