https://www.geeksforgeeks.org/problems/decimal-to-binary-1587115620/1

class Solution {
  public:
    string decToBinary(int n) {
       
       string ans="";
       
       while(n!=0){
           ans.push_back((n%2)+'0');
           n=n/2;
       }
       reverse(ans.begin(), ans.end());
    return ans;
    }
};
