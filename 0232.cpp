class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        std::stack<int> r; // revert
        while(!s.empty())
        {
            r.push(s.top());
            s.pop();
        }

        auto x = r.top();
        r.pop();

        while(!r.empty())
        {
            s.push(r.top());
            r.pop();
        }

        return x;
    }

    /** Get the front element. */
    int peek() {
        auto c = s; // copy

        int x;
        while(c.size() > 1)
            c.pop();

        return c.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }

private:
    std::stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
