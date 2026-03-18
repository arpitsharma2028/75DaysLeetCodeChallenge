class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vec(n,{1,1});
        vec[0].first = 1;
        vec[n-1].second = 1;
        for(int i = 1 ; i < n ; i++){
            vec[i].first = vec[i-1].first * nums[i-1];
            int idx = n-i-1;
            vec[idx].second = vec[idx+1].second * nums[idx+1]; 
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(vec[i].first * vec[i].second);
        }
        return ans;
    }
};