class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n =spells.size();
        int m = potions.size();

        vector<int> ans;
        int possi;
       // sort(spells.begin(),spells.end());
        sort(potions.begin(),potions.end());

        for(int i=0;i<n;i++){
            int start=0;
            int end=potions.size()-1;
            possi=m;
            while(start<=end){
                int mid = start+(end-start)/2; 
                if((long long)(1LL*potions[mid]*spells[i])>=success){
                    possi=mid;
                    end=mid-1;
                }
                else start=mid+1;
            }
        ans.push_back(m-possi);

        }

        return ans;

    }
};
