class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::size_t nCandies = candies.size();
        std::sort(candies.begin(), candies.end());
        auto last = std::unique(candies.begin(), candies.end());
        candies.erase(last, candies.end());
        return std::min(candies.size(), nCandies / 2);
    }
};
