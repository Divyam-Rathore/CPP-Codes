#include <vector>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int xorSum = 0;
        bool allZero = true;

        // Calculate XOR of all elements and check if all are zero
        for (int num : nums) {
            xorSum ^= num;
            if (num != 0) {
                allZero = false;
            }
        }

        // If all elements are zero, no valid subsequence
        if (allZero) {
            return 0;
        }

        // If XOR is non-zero, entire array length is valid
        // Otherwise, remove one element to make XOR non-zero
        return xorSum != 0 ? static_cast<int>(nums.size()) : static_cast<int>(nums.size()) - 1;
    }
};
