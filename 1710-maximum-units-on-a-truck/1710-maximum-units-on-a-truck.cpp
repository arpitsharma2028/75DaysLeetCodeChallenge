class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , [](vector<int>a ,vector<int> b){
            return a[1] > b[1];
        });
        int ans = 0;
        int i = 0;
        while(truckSize>0 && i < boxTypes.size()){
            if(boxTypes[i][0] <= truckSize){
            ans+=boxTypes[i][0]*boxTypes[i][1];
            truckSize -= boxTypes[i][0];
            }
            else if(truckSize >0){
                ans+= truckSize * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            cout<<ans<<endl;
            i++;
        }
        return ans;
    }
};