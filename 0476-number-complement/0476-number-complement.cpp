class Solution {
public:
    int findComplement(int num) {
     int x = log2(num) + 1; 
    for (int i = 0; i < x; i++)  
       num = (num ^ (1 << i)); 
        return num;
    }
};