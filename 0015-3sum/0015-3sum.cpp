class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector <vector <int>> tripletVec;
    for(int i = 0 ; i < n-2 ; i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        int st = i+1 ;
        int end = n-1;
        while(st<end){
            int sum = nums[st]+nums[end]+nums[i];
            if(sum<0){
                st++;
            }
            else if(sum>0){
                end--;
            }
            else{ // sum = 0
            tripletVec.push_back({nums[i],nums[st],nums[end]});
            while(st<end && nums[st] == nums[st+1]){
                st++;
            }
            while(st<end && nums[end] == nums[end-1]){
                end--;
            }
            st++;
            end--;            
            }
        }        
    }
    return tripletVec;
    }
};