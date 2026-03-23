class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        vector<vector<int>> freq(n + 1);
        for (auto i : mp) {
            freq[i.second].push_back(i.first);
        }

        vector<int> ans;
        for (int i = n ; i >= 0; i--) {
            if (!freq[i].empty()){
                for (int j = 0; j < freq[i].size(); j++) {
                    ans.push_back(freq[i][j]);
                    if (ans.size() == k)
                        return ans;
                }
            }
        }
        return ans;
    }
};