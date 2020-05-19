class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int mustRemove = arr.size() / 2;
        int elemsRemoved = 0;
        int numsRemoved = 0;

        std::map<int, int> num2count;
        for(auto i : arr)
            ++num2count[i];

        std::priority_queue<int> counts;
        for(auto [_, count] : num2count)
            counts.push(count);

        while(elemsRemoved < mustRemove)
        {
            auto count = counts.top();
            counts.pop();

            elemsRemoved += count;
            numsRemoved++;
        }

        return numsRemoved;
    }
};
