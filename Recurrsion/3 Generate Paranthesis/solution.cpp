class Solution {
public:
    void solve( int n , vector<string> &ans ,string s,int open , int close){
         if(s.size()==2*n){
            ans.push_back(s);
            return;
         }
         if(open<n && open>=close){
            solve(n,ans,s+"(",open+1,close);
         }
         if(close<n && open>=close){
             solve(n,ans,s+")",open,close+1);
         }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(n,ans,s,0,0);
        return ans;
        

    }
};




class Solution {
public:
    vector<string> result;

    void solve(int open, int n, int close, string& curr) {
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // pick '('
        if (open < n) {
            curr.push_back('(');
            solve(open + 1, n, close, curr);
            curr.pop_back();  // backtrack
        }

        // pick ')'
        if (close < open) {
            curr.push_back(')');
            solve(open, n, close + 1, curr);
            curr.pop_back();  // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(0, n, 0, curr);
        return result;
    }
};
