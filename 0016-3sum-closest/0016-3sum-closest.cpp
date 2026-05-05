class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int ans = nums[0] + nums[1] + nums[2];
     sort(nums.begin() , nums.end());
     for(int i = 0 ; i < nums.size()-2 ; i++){
        int st = i+1 , end = nums.size()-1;
        while(st<end){

            int newSum = nums[i]+nums[end]+nums[st];
            if(newSum == target)return newSum;
            else if (newSum < target) st++;
            else end--;
            
            if(abs(target - ans) > abs(target - newSum))ans = newSum;
        }
     }
     return ans;  
    }
};