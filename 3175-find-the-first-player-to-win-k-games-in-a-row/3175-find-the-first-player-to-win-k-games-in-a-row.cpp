class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
         int i = 0, cur = 0, n = skills.size();
        for (int j = 1; j < n; ++j) {
            if (skills[i] < skills[j]) {
                cur = 0;
                i = j;
            }
            if (++cur == k) break;
        }
        return i;
    }
};