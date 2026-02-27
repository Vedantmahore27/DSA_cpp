class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        while(columnNumber!=0){
            int val = columnNumber%26;
            if(val==0){
                s.push_back('Z');
                columnNumber=columnNumber/26 -1;
                continue;
            }
            s.push_back(char(64+val));
            columnNumber = columnNumber/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
