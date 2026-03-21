class Solution {
  public:
    void bitManipulation(int num, int i) {
        
        int n = num;
        
          int get;
        
        if((n & (1<<i-1))==0)get=0;
        else get=1;
        
        int set =((n | (1<<i-1)));
        
        int clear = ((n & ~(1<<i-1)));
        
        
        cout<<get<<" "<<set<<" "<<clear;
        
        
    }
};
