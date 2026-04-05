class Solution {
public:
    bool BS(vector<int>&nums ,  int target){
        int st = 0 ;
        int end = nums.size()-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid] == target)return true;
            else if(nums[mid] < target)st = mid+1;
            else end = mid-1; 
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n = matrix[0].size();
        int low = 0 , high = m-1;
        int mid = 0;
        while(low <= high){
            mid = low + (high - low)/2;
            if (matrix[mid][0] < target && matrix[mid][n-1] < target){
                low = mid+1;
            }else if(matrix[mid][0] <= target && matrix[mid][n-1] >= target){
                return BS(matrix[mid] , target);
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};