class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        if(v1[1]<v2[1])
            return true;
     if(v1[1]==v2[1]){
         return v1[0]==v2[0];
     }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int overlaps=0;
        sort(intervals.begin(),intervals.end(),comp);
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        while(i<intervals.size()){
            if(intervals[i][0]<end)
            {
                overlaps++;

            }
            else{
                start=intervals[i][0];
                end=intervals[i][1];
            }
            i++;
        }
        return overlaps;
        
    }
};