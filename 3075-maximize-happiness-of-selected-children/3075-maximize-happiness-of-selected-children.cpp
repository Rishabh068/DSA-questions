class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int turn=0;
        long long ans=0;
        sort(happiness.begin(),happiness.end());
        int i=happiness.size()-1;
        while(i>=0&&turn!=k){
            int temp=happiness[i]-turn;
            if(temp<0)
                temp=0;
            ans+=temp;;
            i--;
            turn++;
        }
        return ans;
        
    }
};