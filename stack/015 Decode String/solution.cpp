//stack

class Solution {
public:
    string ans="";
    string decodeString(string s) {
        int n = s.size();
        string curr="";
      
        stack<int> digit;
        stack<string> str;
         int num=0;
        for(auto ch : s){
          if(isdigit(ch)){
            num=num*10+ch-'0';
          }
          else if(ch=='['){
            digit.push(num);
           str.push(curr);
            curr="";
            num=0;

          }
          else if(ch==']'){
                int times;
                string prev;
            if(!digit.empty()){
             times=digit.top();
            digit.pop();
            }
         if(!str.empty()){
           prev=str.top();
            str.pop();
         }
            string temp="";
          for(int i=0;i<times;i++){
             temp +=curr;
           }
           curr=prev+temp;
        }
          else{
             curr.push_back(ch);
          }
        }

        return curr;
        
    }
};

//Recurssion

class Solution {
public:
    
    string solve(int &i, string &s) {
        string res = "";
        int num = 0;

        while(i < s.size()) {

            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {
                i++; // move inside bracket
                string inner = solve(i, s);

                for(int k = 0; k < num; k++) {
                    res += inner;
                }

                num = 0; // reset
            }

            else if(s[i] == ']') {
                return res; // end of current recursion
            }

            else {
                res.push_back(s[i]);
            }

            i++;
        }

        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
    }
};


