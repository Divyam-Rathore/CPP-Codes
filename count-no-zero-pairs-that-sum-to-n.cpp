#include <string>
#include <algorithm>
#include <cstring>

class Solution {
public:
    std::string s;
    long long dp[20][20][2][2];  // DP memoization table

    // Recursive DP function:
    // ind: current digit index (from least significant)
    // carry: carry-over from previous addition
    // za: has the first number had a zero digit yet? (bool)
    // zb: has the second number had a zero digit yet? (bool)
    long long solve(int ind, int carry, bool za, bool zb) {
        if (ind == (int)s.length()) {
            // If no carry remains, found a valid pair
            return carry == 0 ? 1 : 0;
        }

        if (dp[ind][carry][za][zb] != -1) {
            return dp[ind][carry][za][zb];
        }

        int eda = (za ? 0 : 9); // If we already have zero in a, digit can only be 0
        int edb = (zb ? 0 : 9); // Same for b

        int sa = (ind == 0) ? 1 : 0; // Leading digit can't be zero (for the first digit)
        int sb = (ind == 0) ? 1 : 0;

        int targetDigit = s[ind] - '0';

        long long count = 0;

        for (int i = sa; i <= eda; i++) {
            for (int j = sb; j <= edb; j++) {
                int sum = i + j + carry;
                if (sum % 10 == targetDigit) {
                    // Move to next digit, update carry and zero flags
                    count += solve(ind + 1, sum / 10, za | (i == 0), zb | (j == 0));
                }
            }
        }

        return dp[ind][carry][za][zb] = count;
    }

    long long countNoZeroPairs(long long n) {
        s = std::to_string(n);
        std::reverse(s.begin(), s.end()); // Process digits from least significant to most
        std::memset(dp, -1, sizeof(dp));
        return solve(0, 0, false, false);
    }
};
