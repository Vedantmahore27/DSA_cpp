//approach 1 as combination sum 1 

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
            solve(ind+1,target-candidates[ind],n ,ans,candidates,result);//pick
            ans.pop_back();
            }
            
             solve(ind+1,target,n ,ans,candidates,result);
            

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int>ans;
        solve(0,target, n , ans ,candidates , result );
        set<vector<int>> st;
        st.insert(result.begin(),result.end());
        result.assign(st.begin(),st.end());
        return result;
    }
};



//approach 2 for loop wali

class Solution {
public:
    void solve(int n,int ind , int target ,vector<int>& candidates,vector<int>& ans,vector<vector<int>>& finial){
     
   
        if(target==0){
            finial.push_back(ans);
            return;
        }
        
     

     for(int i=ind ; i<n;i++){
        if(ind!=i && candidates[i]==candidates[i-1]) continue;
       // if(candidates[i]>target) break;
        ans.push_back(candidates[i]);

        solve(n,i+1,target-candidates[i],candidates,ans,finial);
        ans.pop_back();
        
     }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ans;
        vector<vector<int>> finial;
        sort( candidates.begin(), candidates.end());
        solve(n,0,target ,candidates,ans,finial);

        return finial;
    }
};
