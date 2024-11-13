class Solution {
public:
    int bs(vector<vector<int>>& items,int price){
        int low=0,high=items.size()-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(items[mid][0]<=price){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int>ans;
        vector<int>mxbeauty;
        mxbeauty.push_back(items[0][1]);
        int maxtill=items[0][1];
       for(int i=1;i<items.size();i++){
            maxtill=max(maxtill,items[i][1]);
           mxbeauty.push_back(maxtill);
           
       }
        for(int i=0;i<queries.size();i++){
            int limit=bs(items,queries[i]);
            if(limit==-1){
                limit=0;
                ans.push_back(0);
            }
            else
            ans.push_back(mxbeauty[limit]);
        }
        return ans;
        
        
    }
};