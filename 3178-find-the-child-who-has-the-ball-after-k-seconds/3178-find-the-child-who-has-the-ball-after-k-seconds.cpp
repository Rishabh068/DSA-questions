class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int x=k/n;
        int y=k%n;
        cout<<y<<endl;
        if(x%2==0)
            return y;
        else
            return n-y;
        
    }
};