#include <vector>
using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int length = r - l;
        
        // dp[v] represents the count of valid sequences ending with value difference v
        vector<int> dp(length + 1, 1);

        for (int i = 1; i < n; i++) {
            int prefixSum = 0, temp;
            
            if (i % 2 == 1) {
                // Odd index: accumulate from left to right
                for (int v = 0; v <= length; v++) {
                    temp = prefixSum + dp[v];
                    dp[v] = prefixSum;
                    prefixSum = temp % MOD;
                }
            } else {
                // Even index: accumulate from right to left
                for (int v = length; v >= 0; v--) {
                    temp = prefixSum + dp[v];
                    dp[v] = prefixSum;
                    prefixSum = temp % MOD;
                }
            }
        }

        int result = 0;
        for (int val : dp) {
            result = (result + val) % MOD;
        }

        // Multiply by 2 for symmetry or problem-specific reason
        return (result * 2) % MOD;
    }
};
