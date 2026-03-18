class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         int n = tokens.size();
         stack<int> st;
         int a , b,c;
         for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
              a =st.top();
             st.pop();
              b = st.top();
             st.pop();
             c= a+b;
             st.push(c);

            }
            else if(tokens[i]=="-"){
              a =st.top();
             st.pop();
              b = st.top();
             st.pop();
              c=b-a;
              st.push(c);
            }
            else if(tokens[i]=="*"){
              a =st.top();
             st.pop();
              b = st.top();
             st.pop();
              c= a*b;
              st.push(c);

            }
            
            else if(tokens[i]=="/"){
              a =st.top();
             st.pop();
              b = st.top();
             st.pop();
              c=b/a;
              st.push(c);
             
            }
            else{
                st.push(stoi(tokens[i]));
            }
         }

        return st.top();
    }
};
