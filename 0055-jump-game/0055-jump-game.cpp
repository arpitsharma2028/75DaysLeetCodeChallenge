class Solution {
public:
    bool canJump(vector<int>& nums) {
        // one thing to notice -> if array doesn't have zeroes then i can always reach at end no matter what value of arr[i].
        // my concern is to move cross zero jump
        // if(nums[0] == 0 && nums.size())

        // note i have to reach at ending index -> arr.size()-1 th index
        int maxLen = 0;
        for(int i = 0 ;i < nums.size()-1 ; i++){
            if(nums[i] == 0 && i >= maxLen)
                return false;
            else
                maxLen = max(maxLen , nums[i]+i);
        }
        return maxLen >= nums.size()-1;
    }
};