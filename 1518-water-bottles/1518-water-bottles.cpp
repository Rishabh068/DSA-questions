class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int curr=0,ans=0;
         while(numBottles!=0){
             ans+=numBottles;
             curr+=numBottles;
             numBottles=curr/numExchange;
             curr=curr%numExchange;
         }
        return ans;
    }
};