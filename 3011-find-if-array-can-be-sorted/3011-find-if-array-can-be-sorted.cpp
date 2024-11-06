class Solution {
public:
    unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],countSetBits(nums[i])});
        }
        int n=nums.size();
        bool swapped;
         for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].second==arr[j+1].second&&arr[j].first > arr[j + 1].first) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
        bool flag=true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i].first>arr[i+1].first){
                flag=false;
                break;
            }
        }
        if(flag)
            return true;
        return false;
}
        
};