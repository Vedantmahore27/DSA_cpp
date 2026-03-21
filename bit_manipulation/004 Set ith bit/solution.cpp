class Solution {
  public:
    int setKthBit(int n, int k) {
      
       int x=1;
       
       return((n | (1<<k)) );
        
    }
};

class Solution {
  public:
    int setKthBit(int n, int k) {
        string ans="";
        while(n>0){
            ans.push_back((n%2)+'0');
            n=n/2;
        }
        
        if(k >= ans.size()){
              ans.resize(k + 1, '0');
         }
        ans[k]='1';
        
        
        int fact=1;
        int finial=0;
        for(int i=0;i<ans.size();i++){
            finial+=(ans[i] - '0') * fact;
            fact=fact*2;
        }
        return finial;
    }
};
