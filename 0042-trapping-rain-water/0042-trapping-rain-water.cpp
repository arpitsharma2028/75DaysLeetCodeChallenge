class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0, Maxwater = 0;
        
        while (l < r) {
            if (height[l] < height[r]) {
                lmax = max(height[l], lmax);
                Maxwater += lmax - height[l];
                l++;
            } 
            else {
                rmax = max(rmax, height[r]);
                Maxwater += rmax - height[r];
                r--;
            }
        }
        return Maxwater;
    }
};