class CustomStack {
public:
    CustomStack(int maxSize)
        : _capacity(maxSize)
    {}

    void push(int x) {
        if(_stack.size() < _capacity)
            _stack.push_back(x);
    }

    int pop() {
        int x = -1;

        if(!_stack.empty())
        {
            x = _stack.back();
            _stack.pop_back();
        }

        return x;
    }

    void increment(int k, int val) {
        for(int i = 0; i < k && i < _stack.size(); ++i)
            _stack[i] += val;
    }

private:
    std::vector<int> _stack;
    int _capacity;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
