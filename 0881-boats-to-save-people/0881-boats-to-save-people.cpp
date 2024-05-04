class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0;
        sort(people.begin(),people.end());
        int start=0,end=people.size()-1;
        while(start<=end){
          
           if(start==end||people[start]+people[end]<=limit){
                start++;
                end--;
                
            }
            else{
                end--;
            }
              boats++;
        }
        return boats;
        
    }
};