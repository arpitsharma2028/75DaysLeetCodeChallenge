class Solution {
public:
    int climbStairs(int n) {
        if(n<2)return n;
        int a = 1 , b = 1;
        int c = a+b;
        for(int i = 2 ; i <= n ; i++){
            c = a + b ; 
            a = b ;
            b = c;
        }
        return c;
    }
};