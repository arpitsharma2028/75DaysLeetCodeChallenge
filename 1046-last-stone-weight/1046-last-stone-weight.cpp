class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        int ans = stones[0];
        if(n == 1)return ans;
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