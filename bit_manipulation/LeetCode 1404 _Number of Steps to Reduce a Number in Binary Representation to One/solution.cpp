class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                // odd → add 1 + divide
                steps += 2;
                carry = 1;
            } else {
                // even → just divide
                steps += 1;
            }
        }

        return steps + carry;
    }
};

//Appraoch 1 : run time
// class Solution {
// public:
//     int numSteps(string s) {
        
//         int n = s.size();
//         long long fact=1;
//         int num=0;
//         int cnt=0;
//         for(int i=n-1;i>=0;i--){
//          if(s[i]=='1'){
//             num=num + fact*1;
//          }
//          fact=fact*2;
//         }
//         while(num!=1){
//             cnt++;
//             if(num%2==0){
//                 num=num/2;
//             }
//             else{
//                num++;
//             }
//         }
//         return cnt;
//     }
// };
