class Solution {
public:
    void solve(int n , int ind ,vector<int> &nums , vector<int> & ans , vector<vector<int>> &finial){
        
        for(int i=ind;i<n;i++){
          if(i > ind && nums[i] == nums[i-1]) continue;
          ans.push_back(nums[i]);
          solve(n,i+1,nums,ans,finial);
          ans.pop_back();
        }
         finial.push_back(ans); 
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> finial;
         sort(nums.begin(), nums.end());
        solve(n,0,nums,ans,finial);

        return finial;
    }
};

//using subset 1

class Solution {
public:
       void solve(int ind, int n ,vector<int>ans, vector<int>nums ,  vector<vector<int>> & result ){

        if(ind==n){
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[ind]);
        solve(ind+1,n,ans,nums,result);
        ans.pop_back();
        solve(ind+1,n,ans,nums,result);
       }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
         vector<vector<int>> result;
         vector<int> ans;
         int ind=0;
        solve(ind,n,ans,nums,result);
        set<vector<int>> res(result.begin(), result.end());
        return vector<vector<int>> (res.begin(),res.end());
        
    }
};
