//my approachO(n! * n)

class Solution {
public:
    void solve(int n,int i,vector<int> nums,vector<int> used,vector<int> res,vector<vector<int>> &finial){
       if(i==n){
        finial.push_back(res);
        return;
       }

       for(int ind = 0; ind<n;ind++){
        if(used[ind]==1)continue;
        used[ind]=1;
        res.push_back(nums[ind]);
        solve(n,i+1,nums,used,res,finial);
        res.pop_back();
        used[ind]=0;
       }


    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
         vector<vector<int>> finial;
         vector<int> res;
         vector<int> used(n,0);
         solve(n,0,nums,used,res,finial);
         set<vector<int>> st(finial.begin(), finial.end());
         finial.clear();
         finial.assign(st.begin(),st.end());
         return finial;
    }
};


class Solution {
public:

    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans){

        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++){

            swap(nums[ind], nums[i]);

            solve(ind + 1, nums, ans);

            swap(nums[ind], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        solve(0, nums, ans);

        return ans;
    }
};
