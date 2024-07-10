class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                if(steps>0)
                steps--;
            }
            else if(logs[i]=="./"){
                //same folder
            }
            else{
                steps++;
            }
        }
        return steps<0?0:steps;
        
    }
};