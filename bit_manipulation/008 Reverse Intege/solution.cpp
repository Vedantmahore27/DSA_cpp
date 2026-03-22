class Solution {
public:
    int reverse(int x) {
        long long n =x;
        long long  num=0;
        bool neg=0;
        if(x<0){
            neg=1;
            n=n*-1;
        }
     
        while(n>0){
          int last=n%10;
          num=(num*10)+last;
          n=n/10;
        }
        if(neg==1)num=num*-1;
        if(num>INT_MAX || num<INT_MIN)return 0;
        return num;
    }
};
