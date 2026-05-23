class Solution {
public:
    int lastStoneWeightOptimized(vector<int>& stones) {
        // basically we have to sort array at each step -> n log n in brute force 
        // but only we are chainging only 1 element
        // why not to use max heap -> insert element in log(n) TC
        // => TC reduced from n^2log(n) to nlog(n) 
        int n = stones.size();
        priority_queue<int>pq;
        for(int i = 0 ; i < n ; i++)pq.push(stones[i]);
        while(pq.size()>1){
            int last = pq.top();
            pq.pop();
            int secLast = pq.top();
            pq.pop();
            last -= secLast;
            pq.push(last);
        }
        int ans = pq.top();
        return ans;
    }
    int lastStoneWeight(vector<int>& stones) {

        return lastStoneWeightOptimized(stones);
        int n = stones.size();
        for(int i = 0 ; i < n && stones.size() > 1 ; i++){
            sort(stones.begin() , stones.end());
            int last = n-i-1  , secLast = n-i-2;
            stones[last] -= stones[secLast];
            swap(stones[last] , stones[secLast]);
            stones.pop_back();
        }
        return stones[0];
    }
};