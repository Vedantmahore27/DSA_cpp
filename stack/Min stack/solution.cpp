class MinStack {
public:
    stack<long long> st;
    long long  min_ele;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            min_ele=val;
            st.push(min_ele);
        }
        else{
            if(min_ele>val){
              st.push(2LL*val-min_ele);
              min_ele=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
           if(st.top()<min_ele){
            min_ele= min_ele*2-st.top();
            st.pop();
           }
           else{
               st.pop();
           }
        }
    }
    
    int top() {
        if(st.empty())return -1;
        else{
        if(st.top()<min_ele) return min_ele;
        else{
            return st.top();
        }
        }
    }
    
    int getMin() {
        return min_ele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
