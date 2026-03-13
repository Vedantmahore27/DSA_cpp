class Solution {
public:
    void solve(int n ,int i ,int k,vector<int> ans,vector<int> &nums ,vector<vector<int>> &finial){
      if(ans.size()==k){
        finial.push_back(ans);
        return;
      }

        for(int ind=i;ind<n;ind++){ //yaha pr pur loop na chala kar aap optimise kar sakte ho
            if(ans.size()==k)continue;
            ans.push_back(nums[ind]);
            solve( n , ind+1 , k, ans,nums ,finial);
            ans.pop_back();
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> finial;
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        vector<int> ans;
        solve(n,0,k,ans,nums,finial);
        return finial;
    }
};
