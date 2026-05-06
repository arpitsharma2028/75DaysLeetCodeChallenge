class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0 , n = nums.size();
        int ans = INT_MAX,sum = 0;
        for(r = 0 ; r < n ; r++){
            sum+= nums[r];
            while(sum >= target && l <= r){
                ans  = min(ans , r-l+1);
                sum-= nums[l++];
            }
        }
        return (ans== INT_MAX ? 0 : ans
        );
    }
};