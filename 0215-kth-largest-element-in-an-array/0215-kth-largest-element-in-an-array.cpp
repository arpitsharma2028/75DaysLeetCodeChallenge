class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        Apporach to solve this problem:
        construct a Min heap
        if element on top of heap is smaller than current element then
        remove top of element and insert current element in it
        at the end
        we have kth largest element at top of heap 
        => TC = nLogK
        => SC => O(k)
        */

        priority_queue<int,vector<int> , greater<int>>minHeap;
        for(int i = 0 ; i < k ; i++)minHeap.push(nums[i]);
        for(int i = k ; i < nums.size() ; i++){
            int curr = nums[i];
            if(curr > minHeap.top()){
                minHeap.pop();
                minHeap.push(curr);
            }
        }
        return minHeap.top();
    }
};