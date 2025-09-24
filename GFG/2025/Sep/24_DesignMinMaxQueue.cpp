class SpecialQueue {
  public:
    queue<int> q;
    deque<int> mindq;
    deque<int> maxdq;
    void enqueue(int x) {
        q.push(x);
        while(mindq.size() && mindq.back()>x){
            mindq.pop_back();
        }
        while(maxdq.size() && maxdq.back()<x){
            maxdq.pop_back();
        }
        mindq.push_back(x);
        maxdq.push_back(x);
    }
    void dequeue() {
        int num=q.front();
        q.pop();
        if(num==mindq.front()){
            mindq.pop_front();
        }
        if(num==maxdq.front()){
            maxdq.pop_front();
        }
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return mindq.front();
    }

    int getMax() {
        return maxdq.front();
    }
};
