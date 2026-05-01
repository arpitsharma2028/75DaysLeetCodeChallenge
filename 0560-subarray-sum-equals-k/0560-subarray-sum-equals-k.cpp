class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSum;
        int count = 0;
        int currentSum = 0;

        // Base case: a prefix sum of 0 has occurred once (for subarrays starting at index 0)
        prevSum[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            // If (currentSum - k) exists in map, it means there is a 
            // subarray ending here that sums to k
            if (prevSum.find(currentSum - k) != prevSum.end()) {
                count += prevSum[currentSum - k];
            }

            // Update the map with the current prefix sum
            prevSum[currentSum]++;
        }
        return count;
    }
};