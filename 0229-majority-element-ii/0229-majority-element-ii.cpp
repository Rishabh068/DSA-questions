class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1,c1=0,c2=0;
         int sz=nums.size();
        vector<int>ans;
       for(auto ele:nums){
            if(ele==num1)
                c1++;
            else if(ele==num2)
                c2++;
            else if(c1==0){
                num1=ele;
                c1=1;
            }
            else if(c2==0){
                num2=ele;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
      c1=0;
        c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1)
                c1++;
            if(nums[i]==num2)
                c2++;
        }
        if(c1>sz/3)
        ans.push_back(num1);
        if(c2>sz/3&&num1!=num2)
        ans.push_back(num2);
        return ans;
    }
};