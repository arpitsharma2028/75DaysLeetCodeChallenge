
class KthLargest {
private:
    // Min-heap to store the k largest elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int size;

public:
    KthLargest(int k, std::vector<int>& nums) {
        size = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // If the heap exceeds size k, remove the smallest element
        if (minHeap.size() > size) {
            minHeap.pop();
        }
        
        // The top of the min-heap is the kth largest element
        return minHeap.top();
    }
};