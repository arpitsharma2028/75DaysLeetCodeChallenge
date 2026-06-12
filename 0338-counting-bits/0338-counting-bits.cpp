class Solution {
public:
    int cntBit(int n){
        int ans = 0;
        while(n){
            ans+= n&1;
            n = n>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i = 0 ; i < n+1 ; i++){
            ans[i] = cntBit(i);
        }
        return ans;
    }
};