class Solution {
public:
    int XORsol (vector<int>&nums){
        int XOR1 = 0 , XOR2 = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            XOR1 = nums[i]^XOR1;
            XOR2 = XOR2^(i+1);
        }
        return XOR1 ^ XOR2;
    }
    int SUMsol(vector<int>&nums){
        int sum = 0;
        int n = nums.size();
        int expSum = n*(n+1)/2;
        for(int i : nums)sum+= i;
        return expSum - sum;
    }
    int missingNumber(vector<int>& nums) {
        return XORsol(nums);
        return SUMsol(nums);
    }
};