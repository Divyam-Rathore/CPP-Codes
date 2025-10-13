#include <string>
#include <vector>

class Solution {
public:
    std::string removeSubstring(std::string s, int k) {
        // Stack to store pairs of (character, consecutive count)
        std::vector<std::pair<char, int>> st;
        
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                // Increment count if same character as the last
                st.back().second++;
            } else {
                // Push new character group
                st.push_back({c, 1});
            }
            
            int n = st.size();
            // Check if last two groups form a k-balanced substring: 
            // k '(' followed by k ')'
            if (n >= 2 && 
                st[n-2].first == '(' && st[n-2].second >= k &&
                st[n-1].first == ')' && st[n-1].second == k) {
                
                // Remove k '(' from the second last group
                st[n-2].second -= k;
                
                // Remove the entire last group of ')'
                st.pop_back();
                
                // If after removing, '(' group is empty, pop it as well
                if (!st.empty() && st.back().second == 0) {
                    st.pop_back();
                }
            }
        }
        
        // Reconstruct the final string from remaining groups
        std::string result;
        for (auto& p : st) {
            result += std::string(p.second, p.first);
        }
        
        return result;
    }
};
