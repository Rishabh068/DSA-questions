class MyCircularDeque {
public:
    int sz;
    int total;
    class Node{
        public:
        int val;
        Node* next;
        Node* prev;
        Node(int x){
            this->val=x;
            this->next=nullptr;
            this->prev=nullptr;
        }
    };
    Node *head;
    Node* tail;
    MyCircularDeque(int k) {
        this->sz=0;
        this->total=k;
         head=new Node(-1);
        tail=new Node(-1);
        head->next=tail;
        tail->prev=head;
        
    }
    
    bool insertFront(int value) {
        if(sz==total)
            return false;
  
            Node *newnode=new Node(value);
           newnode->next=head->next;
           newnode->prev=head;
            head->next->prev=newnode;
             head->next=newnode;
              sz++;
            return true;
            
       
        
    }
    
    bool insertLast(int value) {
          if(sz==total)
            return false;
        Node* newnode=new Node(value);
         newnode->next=tail;
        newnode->prev=tail->prev;
        tail->prev->next=newnode;
        tail->prev=newnode;
        sz++;
        return true;
        
    }
    
    bool deleteFront() {
        if(head->next==tail)
            return false;
        else
            head->next=head->next->next;
            head->next->prev=head;
        sz--;
        return true;
        
    }
    
    bool deleteLast() { 
        if(head->next==tail||tail->prev==head)
            return false;
        tail->prev->prev->next=tail;
        tail->prev=tail->prev->prev;
        sz--;
        return true;
        
    }
    
    int getFront() {
        if(sz==0)
            return -1;
        return head->next->val;
        
    }
    
    int getRear() {
        if(sz==0)
            return -1;
        else
            return tail->prev->val;
        
    }
    
    bool isEmpty() {
        if(sz==0)
            return true;
        return false;
        
    }
    
    bool isFull() {
        if(sz==total)
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */