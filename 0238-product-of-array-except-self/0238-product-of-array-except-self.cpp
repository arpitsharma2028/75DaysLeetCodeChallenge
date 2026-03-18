class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec(n,1);
        vec[0]= 1;
        for(int i = 1 ; i < n ; i++){
            vec[i] = vec[i-1] * nums[i-1];
        }
        int mul = nums[n-1];
        for(int i = n-2 ; i>=0 ; i--){
            vec[i]*=mul;
            mul*= nums[i];
        }
        return vec;
    }
};