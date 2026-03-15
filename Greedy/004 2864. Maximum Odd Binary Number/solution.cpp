class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
        }

        if(cnt>=1){
            cnt--;
            s[n-1]='1';
        }
        for(int i=0;i<n-1;i++){
         if(cnt>0){
            s[i]='1';
            cnt--;
         }
         else{
            s[i]='0';
         }
        }
        return s;
    }
};
