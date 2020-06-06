class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto it_dst = nums1.begin();

        std::vector<int> nums1_copy(nums1.begin(), nums1.begin() + m);
        auto it_src1 = nums1_copy.begin();
        auto it_src2 = nums2.begin();
        while(it_src1 != nums1_copy.end() && it_src2 != nums2.end())
        {
            if(*it_src1 <= *it_src2)
                *it_dst++ = *it_src1++;
            else
                *it_dst++ = *it_src2++;
        }
        while(it_src1 != nums1_copy.end())
            *it_dst++ = *it_src1++;
        while(it_src2 != nums2.end())
            *it_dst++ = *it_src2++;
    }
};
