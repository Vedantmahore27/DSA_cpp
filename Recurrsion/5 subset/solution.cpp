class Solution {
public:
    void solve(int n , int i , vector<int> &nums ,vector<int> ans, vector<vector<int>> &finial ){
        if(i==n){
            finial.push_back(ans);
            return; 
        }
        //pick
        ans.push_back(nums[i]);
        solve(n , i+1 , nums , ans, finial);

        ans.pop_back();
        
        solve(n , i+1 , nums , ans, finial);

    }
    //subsequence subset same hai 
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> finial;
        vector<int> ans;
        solve(n,0,nums,ans,finial);

        return finial;
    }
};
