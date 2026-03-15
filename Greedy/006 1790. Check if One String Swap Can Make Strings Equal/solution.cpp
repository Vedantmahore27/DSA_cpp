class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        if(s1.size()!=s2.size())return false;
        int cnt =0;
        char prev1 , prev2;

        for(int i=0;i<s1.size();i++){
          if(s1[i]!=s2[i] && cnt==1){
               if(prev1==s2[i] && prev2==s1[i])cnt++;
               else return false;
           } 
           else if(s1[i]!=s2[i]){
              cnt++;
              prev1=s1[i];
              prev2=s2[i];
           }
        }
        if(cnt==1)return false;
        if(cnt==2)return true;
        return false;
    }
};
