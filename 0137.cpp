class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int, int> m;
        for(const auto& num : nums)
        {
            m[num]++;
            if(m[num] == 3)
                m.erase(num);
        }
        return m.begin()->first;
    }
};
