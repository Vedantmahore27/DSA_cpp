class Solution {
  public:
    bool checkKthBit(int n, int k) {
      
      if((n & 1<<k)!=0)return true;
      else return false;
      
    }
};


// class Solution {
//   public:
//     bool checkKthBit(int n, int k) {
//       string ans="";
//       while(n>0){
//           ans.push_back(((n%2)+'0'));
//           n=n/2;
//       }
//      if(k >= ans.size()) return false; // out of range
        
//       if(ans[k]=='0')return false;
//       else return true;
//     }
// };
