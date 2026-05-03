class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int mid = 0;

    while(mid<n && nums[mid] <= 0)mid++ ;
    // reverse vector till mid => make array in incresing order sorting for -ve element => final result like -1 -2 -3
    for(int i = 0 ; i < n ; i++)nums[i]*= nums[i];
    reverse(nums.begin(), nums.begin() + mid);

    // 4. In-place merge the two sorted halves: [0, mid) and [mid, n)
    inplace_merge(nums.begin(), nums.begin() + mid, nums.end());
    return nums;
    }
};