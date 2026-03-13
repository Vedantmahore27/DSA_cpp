class Solution {
  public:
    void solve(int n, int i ,string &s,string ans,vector<string> &finial){
        if(i==n){
            finial.push_back(ans);
            return;
        }
        
        //add space
         ans.push_back(' ');
         ans.push_back(s[i]);
      
         solve( n ,i+1,s,ans,finial);
         
         //do not add space
         ans.pop_back();
         ans.pop_back();
         ans.push_back(s[i]);
         
         solve( n ,i+1,s,ans,finial);
         
        // ans.pop_back(); this require when you pass by reference &ans
    }
    vector<string> permutation(string s) {
       
       string ans="";
       ans.push_back(s[0]);
       vector<string> finial;
       int n=s.size();
       
       solve( n ,1,s,ans,finial);
       return finial;
        
    }
};
