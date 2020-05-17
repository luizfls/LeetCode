class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else if(nums[0] != nums[1])
            return nums[0];
        else if(nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];

        int single;
        int left = 2;
        int right = nums.size() - 2;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            {
                single = nums[mid];
                break;
            }

            if(nums[mid - 1] == nums[mid])
                mid = mid - 1;

            auto rightSize = right - mid;
            if(rightSize % 2 == 0)
                right = mid;
            else
                left = mid + 2;
        }

        return single;
    }
};
