class Solution {
public:
    bool helper(vector<int>& position, int m,int force){
        int balls=0;
        int i=0;
        int lastpos=-1;
        while(i<position.size()){
            if(lastpos==-1||abs(lastpos-position[i])>=force){
                lastpos=position[i];
                balls++;
            }
            i++;
            
        }
        cout<<force<<" "<<balls<<endl;
        if(balls>=m)
            return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=0,high=position[position.size()-1];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(position,m,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};