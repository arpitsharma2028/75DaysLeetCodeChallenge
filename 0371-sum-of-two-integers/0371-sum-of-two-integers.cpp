class Solution {
public:
    int helper(int a , int b){
        if(b == 0 )return a;
        return helper(a^b , (a&b)<<1);
    }
    int getSum(int a, int b) {
        return helper(a,b);
        while (b != 0) {
            // 1. Find the carry bits
            // We cast to unsigned int to prevent overflow runtime errors in C++
            unsigned int carry = (unsigned int)(a & b) << 1;
            
            // 2. Sum of bits where at least one is 0
            a = a ^ b;
            
            // 3. Move carry to b to add it in the next iteration
            b = carry;
        }
        return a;
    }
};