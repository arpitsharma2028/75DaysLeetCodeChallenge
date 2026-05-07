class Solution {
public:
    /*
        we will use sliding window technique to solve this problem,
        simple try to use map as basket,
        simply put fruit in basket if total baskets.
        if total baskets we have are greater than 2 then , remove fruits from that basket in which 
        fruits were picked earlist.
        // TC : O(N)
        // Sc = O(1)
        approach : sliding window;
    */
    int totalFruit(vector<int>& fruits){
        unordered_map<int,int>baskets;
        int cnt = 0;
        int l = 0;
        for(int r = 0 ; r < fruits.size() ; r++){
            baskets[fruits[r]]++;
            if(baskets.size() > 2 && l < r){
                baskets[fruits[l]]--;
                if(baskets[fruits[l]] == 0){
                    baskets.erase(fruits[l]);
                }
                l++ ;
            }else{
            int temp = 0 ;
            for (auto [key , val] : baskets){
                temp+= val;
            }
            cnt = max(cnt , temp);
            }
        }
        return cnt;
    }
};