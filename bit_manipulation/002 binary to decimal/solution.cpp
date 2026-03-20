class Solution {
  public:
    int binaryToDecimal(string &b) {
        int n = b.size();
        int factor=1;
        int ans=0;
        for(int i=n-1 ; i>=0 ; i--){
          ans=ans+(factor*(b[i]-'0'));
          factor=factor*2;
       }
       return ans;
    }
};
