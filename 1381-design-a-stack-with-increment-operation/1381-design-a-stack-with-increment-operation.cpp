class CustomStack {
public:
    int sz=0;
    vector<int>vec;
    CustomStack(int maxSize) {
        sz=maxSize; 
    }
    
    void push(int x) {
        if(vec.size()!=sz){
            vec.push_back(x);
        }
        
    }
    
    int pop() {
        if(vec.size()!=0){
        int x=vec[vec.size()-1];
        vec.pop_back();
            return x;
        }
        else
            return -1;
        
        
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k&&i<vec.size();i++){
            vec[i]+=val;        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */