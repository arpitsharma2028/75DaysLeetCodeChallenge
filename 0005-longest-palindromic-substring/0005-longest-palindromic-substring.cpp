class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        // dp[i][j] will be true if substring s[i...j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int startIdx = 0;
        int maxLen = 1;

        // Base case: All single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check substrings of length 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Ending index

                // Condition 1: Outer characters must match
                if (s[i] == s[j]) {
                    // Condition 2: Inner substring must be a palindrome 
                    // (if length is 2, there is no inner substring, so it's automatically true)
                    if (len == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;

                        // Track the longest valid palindromic window found
                        if (len > maxLen) {
                            maxLen = len;
                            startIdx = i;
                        }
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};