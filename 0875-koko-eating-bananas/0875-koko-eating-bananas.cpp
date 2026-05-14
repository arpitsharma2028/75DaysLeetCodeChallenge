class Solution {
public:
    bool isPossible(vector<int>&piles ,int mid , int timeLimit){
        long long  time = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            if(piles[i] % mid == 0){
                time+= piles[i]/mid;
            }else{
                time+= (piles[i]/mid )+1 ;
            }
        }
        return time <= timeLimit ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1 , end = 0;
        for(int i :  piles)end = max(end,i);
        int ans = INT_MAX;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(isPossible(piles,mid,h)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;

    }
};