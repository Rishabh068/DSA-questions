class Solution {
public:
    int helper(string num){
        int ans=0;
        for(int i=0;i<num.length();i++){
            ans+=num[i]-'0';
        }
        return ans;
       
    }
    int getLucky(string s, int k) {
        string num="";
        for(int i=0;i<s.length();i++){
            num+=to_string(s[i]-'a'+1);
        }
        int sum=0;
      while(k--){
          sum=helper(num);
          num=to_string(sum);
             
      }
        return sum;
        
    }
};