class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> counts;
        int max_freq = 0;
        for (char task : tasks) {
            counts[task]++;
            max_freq = std::max(max_freq, counts[task]);
        }
        
        // Count how many tasks have the maximum frequency
        int max_freq_count = 0;
        for (auto const& [task, freq] : counts) {
            if (freq == max_freq) {
                max_freq_count++;
            }
        }
        
        // Calculate the minimum blocks needed using the formula:
        // (max_freq - 1) * (n + 1) + max_freq_count
        int ans = (max_freq - 1) * (n + 1) + max_freq_count;
        
        // Return the maximum of the calculated slots or the total task size
        return std::max((int)tasks.size(), ans);
    }
};