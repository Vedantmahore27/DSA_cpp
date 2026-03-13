class Solution {
public:
    void solve(int ind, int target , int n ,vector<int> ans, vector<int>& candidates , vector<vector<int>> &result  ){
            if(ind==n){
            if(target==0){
                result.push_back(ans);
                
            }
            return;
        }

            if(candidates[ind]<=target){
            ans.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],n ,ans,candidates,result);//pick
            ans.pop_back();
            }
            
             solve(ind+1,target,n ,ans,candidates,result);
            

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int>ans;
        solve(0,target, n , ans ,candidates , result );
        return result;
    }
};
