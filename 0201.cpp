class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        std::bitset<32> lower(m);
        int leftmost1bit = -1;
        for(int i = lower.size() - 1; i >= 0; --i)
            if(lower[i])
            {
                leftmost1bit = i;
                break;
            }

        std::bitset<32> upper(n);
        for(int i = upper.size() - 1; i > leftmost1bit; --i)
            if(upper[i])
                return 0;

        std::bitset<32> bs(lower);
        for(unsigned int i = lower.to_ulong(); i <= upper.to_ulong(); ++i)
            bs &= std::bitset<32>(i);

        return bs.to_ulong();
    }
};
