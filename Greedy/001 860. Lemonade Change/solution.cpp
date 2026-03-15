class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        //greedy -> because you cant use future money to correct mistake you did in the past

        int cnt5=0,cnt10=0,cnt20=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5)cnt5++;

            else if(bills[i]==10){
                if(cnt5<=0)return false;
                cnt10++;
                cnt5--;
            }
            else{
                if(cnt10>0 && cnt5>0 ){
                    cnt10--;
                    cnt5--;
                    cnt20++;
                }
                else if(cnt5>=3){
                    cnt5=cnt5-3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
        
        
    }
};
