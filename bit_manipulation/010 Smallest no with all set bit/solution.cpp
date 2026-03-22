class Solution {
public:
    int smallestNumber(int n) {
       //no of bit jitne hai utne ko 1 bana do
       int x=1;
       while(x<=n){
        x=x*2;
       }
       return x-1;
    }
};
