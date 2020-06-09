class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;

        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;

            // happy case
            if(nums[mid] == target)
                return mid;

            // trivial case
            else if(nums[left] <= nums[right])
            {
                if(target < nums[mid])
                    right = mid - 1;
                else /* target > nums[mid] */
                    left = mid + 1;
            }

            // wacky case #1
            else if(target < nums[mid])
            {
                if(nums[mid] < nums[right])
                    right = mid - 1;
                else if(target >= nums[left])
                    right = mid - 1;
                else /* target < nums[left] */
                    left = mid + 1;
            }

            // wacky case #2
            else if(target > nums[mid])
            {
                if(nums[mid] > nums[left])
                    left = mid + 1;
                else if(target <= nums[right])
                    left = mid + 1;
                else /* target < nums[left] */
                    right = mid - 1;
            }
        }

        return -1;
    }
};
