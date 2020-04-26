class FreqStack {
public:
    FreqStack() {

    }

    void push(int x) {
        num2freq[x]++;
        freq2nums[num2freq[x]].push(x);
    }

    int pop() {
        int x = freq2nums.begin()->second.top();

        freq2nums.begin()->second.pop();
        if(freq2nums.begin()->second.empty())
            freq2nums.erase(freq2nums.begin());

        num2freq[x]--;
        if(num2freq[x] == 0)
            num2freq.erase(x);

        return x;
    }

private:
    std::map<int, std::stack<int>, std::greater<int>> freq2nums;
    std::unordered_map<int, int> num2freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
