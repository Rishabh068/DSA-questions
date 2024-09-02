class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
       long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        k=k%sum;
        for(int i=0;i<n;i++){
            if(chalk[i]>k)
                return i;
            k-=chalk[i];
        }
        return n-1;
        
    }
};