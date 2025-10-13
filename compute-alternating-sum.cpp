#include <vector>

class Solution {
public:
    int alternatingSum(const std::vector<int>& nums) {
        int result = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            // Add element if index is even, subtract if odd
            if (i % 2 == 0)
                result += nums[i];
            else
                result -= nums[i];
        }
        return result;
    }
};
