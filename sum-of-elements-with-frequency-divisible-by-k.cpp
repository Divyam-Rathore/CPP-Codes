#include <vector>
#include <unordered_map>

class Solution {
public:
    int sumDivisibleByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;

        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        int sum = 0;

        // Add the value * frequency to sum if the frequency is divisible by k
        for (const auto& entry : freq) {
            int value = entry.first;
            int count = entry.second;

            if (count % k == 0) {
                sum += value * count;
            }
        }

        return sum;
    }
};
