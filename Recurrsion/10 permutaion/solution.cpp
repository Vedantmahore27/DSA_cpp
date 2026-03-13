//if you remember this pattern we see in combination sum 2 

class Solution {
public:
    void solve(int n, int i,vector<int> &nums , vector<int> &res ,vector<int> &used , vector<vector<int>> &finial){
       if(i==n){
        finial.push_back(res);
        return;
       }
       
       for(int ind=0;ind<n;ind++){
        if(used[ind]==1)continue;
          used[ind]=1;
          res.push_back(nums[ind]);
          solve(n,i+1,nums,res,used,finial);
          res.pop_back();
          used[ind]=0;
       }
       
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<int> res;
        vector<vector<int>> finial;
        vector<int> used(n,0);
        solve(n,0,nums,res,used,finial);
        return finial;

    }
};
