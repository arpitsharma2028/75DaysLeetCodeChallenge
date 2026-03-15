class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,0);
        for(int i : nums)arr[i-1]++;
        vector<int>ans;
        for(int i = 0 ; i < n ; i++)if(!arr[i])ans.push_back(i+1);
        return ans;
    }
};