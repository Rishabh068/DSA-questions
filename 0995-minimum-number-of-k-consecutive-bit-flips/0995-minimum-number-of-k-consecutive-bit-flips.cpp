class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>isflipped(n,false);
        int flips=0,currflipsfori=0;
        for(int i=0;i<n;i++){
            if(i-k>=0&&isflipped[i-k]==true){
                currflipsfori--;
            }
            if(currflipsfori%2==nums[i]){
                if(i+k>n)
                    return -1;
                currflipsfori++;
                flips++;
                isflipped[i]=true;
            }
        }
        return flips;
    }
};