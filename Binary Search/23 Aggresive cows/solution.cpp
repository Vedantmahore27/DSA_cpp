class Solution {
  public:
    bool possible(int k,int mid,vector<int> &stalls){
        int position=stalls[0];
        int cow=1;
        
        for(int i =0;i<stalls.size();i++){
            if(position+mid<=stalls[i]){
                cow++;
                position=stalls[i];
            }
        }
        return (cow>=k);
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        //maximize minimum distance
        
        //search space is minimum distance 
        //range will be
        
        //min dist bten two cows =1
        // max dit btwn two cows = larest_ele-smallest_ele
        sort(stalls.begin(),stalls.end());
        int n= stalls.size();
        int start=1;
        int ans=-1;
        int end= stalls[n-1]-stalls[0];
        
        while(start <= end){
            int mid = start+(end-start)/2;
            if(possible(k,mid,stalls)){  //here mid is minimum distance btwn two cows;
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return ans;
        
        
    }
};
