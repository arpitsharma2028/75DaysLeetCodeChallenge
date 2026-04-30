class Solution {
public:
    // directly copied 
    int longestConsecutive(vector<int> & nums) {
        unordered_set <int> st;
        for (int num : nums) {
            st.insert(num);
        }
        int longestConsecutiveSequence = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while (st.find(currentNumber + 1) != st.end()) {
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence =
                    max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};