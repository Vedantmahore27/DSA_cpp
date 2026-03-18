class StockSpanner {
public:
    int i;
    stack<pair<int,int>> st;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        i++;
        if(st.empty()){
            st.push({price,i});
            return 1;
        }

        else if(!st.empty() && st.top().first<=price){
           
         
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            if(st.empty()){
                st.push({price,i});
                return i;
            };
            
            pair<int,int>  x= st.top();
            st.push({price,i});
            return i-x.second;
        }
        else{
            pair<int,int>  x= st.top();
            st.push({price,i});
            return i-x.second;
        }
        return i;
        
    }
};
 

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
