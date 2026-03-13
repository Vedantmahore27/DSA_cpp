class Solution {
  public:
    void solve(int n ,vector<int>& arr,int k , bool &ans ){
        if(n<0){
            if(k==0)ans= true;
            return;
        }
        if (ans)return;          // ye check karna imp hai nahi to run time error
         //pick
        if(k>=arr[n])solve(n-1,arr,k-arr[n],ans);
        
        //nonpick
        solve(n-1,arr,k,ans);
        return;
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
         bool ans=false;
         solve(n-1,arr,k , ans);
         return ans;
        
    }
};
