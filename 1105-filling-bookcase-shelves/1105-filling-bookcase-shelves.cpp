class Solution {
public:
   vector<vector<int>> memo;
int dp(int i,vector<vector<int>>& books,int shelfwidth,int width,int h)
{
    if(i>=books.size())
        return h;
    if(memo[i][width]!=-1)
        return memo[i][width];
    int q=h+dp(i+1,books,shelfwidth,books[i][0],books[i][1]);
    if(width+books[i][0]<=shelfwidth)
        q=min(q,dp(i+1,books,shelfwidth,width+books[i][0],max(h,books[i][1])));
    return memo[i][width]=q;
}
int minHeightShelves(vector<vector<int>>& books, int shelf_width) 
{
    memo.resize(books.size(),vector<int>(shelf_width+1,-1));
    return dp(0,books,shelf_width,0,0);
}
};