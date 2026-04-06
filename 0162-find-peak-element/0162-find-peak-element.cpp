class Solution {
public:
    int peakEl (vector<int>&nums){
        int n = nums.size() ,st = 0 , end = n-1;
        int mid = 0;
        while(st <= end){
            mid = st +(end-st)/2;
           if(mid+1 < n && nums[mid] < nums[mid+1])st = mid+1;
           else end = mid-1;
        }
        return end+1;
    }
    int findPeakElement(vector<int>& nums) {
        return peakEl(nums) ;
    }
};