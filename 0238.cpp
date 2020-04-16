class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 1);

        int accumulator = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            accumulator *= nums[i - 1];
            out[i] *= accumulator;
        }

        accumulator = 1;
        for(int i = nums.size() - 2; i >= 0 ; --i)
        {
            accumulator *= nums[i + 1];
            out[i] *= accumulator;
        }

        return out;
    }
};
