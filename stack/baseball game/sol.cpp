class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(operations[i]=="C"){
                st.pop();
            }
            else if (operations[i]=="+"){
                int first=(st.top());
                st.pop();
                int second=(st.top());
                st.push(first);
                st.push(first+second);
            }
            else if(operations[i]=="D"){
                int first= (st.top());
                st.push(first*2);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }

        int cnt =0;

        while(!st.empty()){
            cnt+=st.top();
            st.pop();
        }
        return cnt;
    }
};
