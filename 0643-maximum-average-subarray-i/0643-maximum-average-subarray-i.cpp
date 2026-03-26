class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0 ;
        int r =  0, l = 0;
        double ans = INT_MIN;
        while(r < nums.size()){
            sum+= nums[r++];
            double len = r-l;
            if(len < k)continue;
            if(sum/len > ans)ans = sum/len;
            sum-= nums[l++];
        }
        return ans;
    }
};