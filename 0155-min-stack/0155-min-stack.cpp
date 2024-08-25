class MinStack {
    int minVal;
    int arr[100000]= {0};
    int topIndex;
public:
    MinStack() {
        minVal = 0;
        topIndex = -1;
    }
    
    // Idea is to store {val, minVal} always. 2 index entry.
    void push(int val) {
        if (topIndex >= 100000) {
            return;
        }
        if (topIndex < 0) {
            minVal = val;
        } else {
            minVal = min(minVal, val);   
        }
        topIndex++;
        arr[topIndex] = val;
        topIndex++;
        arr[topIndex] = minVal;
    }
    
    void pop() {
        if (topIndex <=0) {
            return;
        }
        int popElement = arr[topIndex];
        topIndex-=2;
        if ((minVal == popElement) && topIndex>=0) {
            minVal = arr[topIndex];
        }
    }
    
    int top() {
        return arr[topIndex-1];
    }
    
    int getMin() {
        return arr[topIndex];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */