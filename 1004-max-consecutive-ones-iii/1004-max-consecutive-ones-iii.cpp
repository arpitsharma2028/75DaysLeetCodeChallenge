class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0 , n = nums.size() , cnt= 0 , zero_cnt = 0;
        while(r<n){
            if(nums[r] == 0)zero_cnt++;
            if(zero_cnt > k){
                if(nums[l] == 0)zero_cnt--;
                l++;
            }
            if(zero_cnt <= k){
                cnt = max(r-l+1 , cnt);
            }
            r++;
        }
        return cnt;
    }
};