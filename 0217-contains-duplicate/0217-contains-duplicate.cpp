class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        int n = nums.size();
        for(int idx = 0 ; idx < n ; idx++){
            if(s.find(nums[idx]) != s.end())return true;

            s.insert(nums[idx]);
        }
        return false;
    }
};