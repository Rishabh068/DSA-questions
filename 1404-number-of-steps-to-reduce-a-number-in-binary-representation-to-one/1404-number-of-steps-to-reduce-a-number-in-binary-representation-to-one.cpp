class Solution {
public:
    int helper(long long int num){
        return num%2==0;
    }
    int numSteps(string s) {
     int res = s.size() - 1, carry = 0;
    for (auto i = s.size() - 1; i > 0; --i)
        if (s[i] - '0' + carry == 1) {
            carry = 1;
            ++res;
        }
    return res + carry;
    }
};