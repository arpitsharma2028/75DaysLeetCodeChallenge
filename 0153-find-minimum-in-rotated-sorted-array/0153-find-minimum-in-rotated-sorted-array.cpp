class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int st = 0 , n =  nums.size() ,  end = n-1 , mid ;

        while(st <= end){
            mid = st + (end-st)/2 ;
            if(st == end){
                return nums[mid];
            }

           if(nums[mid] < nums[end]){ // go to right side
            end = mid;
           }
           else {
            st = mid+1;
           }
        }
        return -1 ;        
    }
};