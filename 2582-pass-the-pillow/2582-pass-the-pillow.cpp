class Solution {
public:
    int passThePillow(int n, int t) {
     int rounds = t/(n-1); 
        int k = t % (n-1); 
        return rounds % 2 == 0 ? k+1 : n - k;
        
    }
};