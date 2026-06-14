class Solution {
public:
    int reverseBits(int n) {
        // reverse bits here doesn't mean to complement each bit of a number, 
        // it it means reversing position ,  think like how we reverse a array elements position.
        int ans = 0;
        for(int i = 0 ; i < 31 ; i++){
            int bit = n&1;
            ans = ans|bit;
            ans = ans<<1;
            n = n>>1;
        }
        return ans;
    }
};