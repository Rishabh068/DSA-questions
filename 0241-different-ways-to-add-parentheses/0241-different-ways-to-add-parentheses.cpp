class Solution {
public:
    
    int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    
    vector<int>helper(string exp){
        vector<int>ans;
        if(exp.size()==1)
        {
            ans.push_back(stoi(exp));
            return ans;
        }
        bool noop=true;
        for(int i=0;i<exp.size();i++){
            if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'){
                noop=false;
                vector<int>left=helper(exp.substr(0,i));
                vector<int>right=helper(exp.substr(i+1));
                for(auto x:left){
                    for(auto y:right){
                        ans.push_back(perform(x,y,exp[i]));
                    }
                }
            }
        }
        if(noop)
            ans.push_back(stoi(exp));
        return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
        vector<int>ans=helper(exp);
        return ans;
    }
};