// User function template for C++
class Solution {
  public:
    void solve(int n , string s , vector<string> &res , int one , int zero){
       
        if(s.size()==n){
            res.push_back(s);
            return;
            
        }
        if(one>=zero){
        s.push_back('1');
        solve( n ,  s , res ,  one+1 ,  zero);
        s.pop_back();
        }
        if(one>zero){
             s.push_back('0');
             solve( n ,  s , res ,  one ,  zero+1);
        }
    }
    vector<string> NBitBinary(int n) {
        vector<string> res;
        string s= "1";
        solve(n,s,res,1,0);
        return res;
    }
};
