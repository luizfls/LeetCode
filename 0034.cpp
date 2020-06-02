class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = std::lower_bound(nums.begin(), nums.end(), target);
        auto ub = std::upper_bound(nums.begin(), nums.end(), target);

        if(lb == ub)
            return {-1, -1};
        else
            return {static_cast<int>(std::distance(nums.begin(), lb)),
                    static_cast<int>(std::distance(nums.begin(), ub) - 1)};
    }
};
