class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,int>>stones;
        for(int i=0;i<aliceValues.size();i++){
            stones.push_back({aliceValues[i]+bobValues[i],i});
        }
        sort(stones.begin(),stones.end(),greater<>());
        int a=0,b=0,turn=1;
        for(int i=0;i<bobValues.size();i++){
            if(turn){
                a+=aliceValues[stones[i].second];
            }
            else{
                b+=bobValues[stones[i].second];
            }
            turn^=1;
        }
        if(a>b)
            return 1;
        else if(b>a)
            return -1;
        else
            return 0;
    }
};