class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 , n = height.size() , r = n-1;
        int ans = INT_MIN;
        while(l<r){
            int area = min(height[l],height[r])*(r-l);
            ans = max(area , ans);
            if(height[l] < height[r])l++;
            else r--;
        } 
        return ans;
    }
};