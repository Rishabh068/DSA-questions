class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {   
        vector<pair<int,int>>vec;
        
        for(int i = 0;i<nums.size();++i){
            int num = nums[i];
          string number = to_string(num); 
            string formed = "";
          for(int j= 0;j<number.size();++j){
              formed+=(to_string(mapping[number[j]-'0']));
          }
          int value = stoi(formed);
          vec.push_back({value,i});
        }
        
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(auto pa:vec){
            int found = nums[pa.second];
            ans.push_back(found);
        }
        
        return ans;
    }
};
