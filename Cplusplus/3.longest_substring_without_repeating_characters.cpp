#include <iostream>
#include <unordered_map>
class Solution {
    public:
        int lenthOfLongestSubstring(string s) {
            std::unordered_map<char, size_t> mp;
            std::size_t s_len = s.size();
            std::vector dp(s_len + 1, 0);
            for (std::size_t i = 1; i <= s_len; ++i) {
                if (s[i] == s[i-1]) {
                    dp[i] = 1;
                }
            } 
        }
};
