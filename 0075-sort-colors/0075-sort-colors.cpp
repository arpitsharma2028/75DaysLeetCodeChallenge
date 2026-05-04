class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() , r = n-1 , l = 0 , m = 0;

        while(m <= r){
            if(nums[m] == 2){
                swap(nums[r],nums[m]);
                r--;
            }else if(nums[m] == 0){
                swap(nums[m],nums[l]);
                l++,
                m++;
            }else{
                m++;
            }
        }

    }
};