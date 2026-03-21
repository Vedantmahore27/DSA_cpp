class Solution {
  public:
    int toggleBits(int n, int l, int r) {
      //ye dekh ye soch ki xor to lena padega toggle ke liye 
      
      //now toggle ke is part me 111 kaise banaye
      
     int mask=(((1<<r-l+1)-1)<<l-1);
     
      return n^mask;
    }   
};
