class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        string str="";
        for(int i =0;i<n;i++){
            if(path[i]=='/'){
                 if(!st.empty() && str=="..")st.pop();
                 else if(str!="" && str!=".." && str!=".")st.push(str);
               //  else if()
                 str="";
            }
            
            else str.push_back(path[i]);

        }
         if(!st.empty() && str=="..")st.pop();
         else if(str!="" && str!=".." && str!=".")st.push(str);

        string ans="";
        str="";
        while(!st.empty()){
            str=st.top();
            st.pop();
            //if(!st.empty() &&str=="..")st.pop();
             ans= "/"+str+ans;
        }
        if (ans=="")return "/";
        return ans;
    }
};
