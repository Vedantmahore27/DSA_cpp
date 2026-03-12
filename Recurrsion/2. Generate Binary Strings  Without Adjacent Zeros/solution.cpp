class Solution {
public:
    //catch 0 ke bad zero nahi ana chahiye
    void solve(vector<string> &ans , int n , string s){
        if(n==0){
            ans.push_back(s);
            return;
        }
       
        if((s.size()>0 && s.back()=='1') || (s.size()==0))solve(ans,n-1,s+"0");
        solve(ans,n-1,s+"1");
            
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s="";
         solve(ans,n , s);
         return ans;
    }
};
