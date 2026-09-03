class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b){
            if(a[1] != b[1]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int totalUnits = 0;
        for(auto &box : boxTypes){
            int boxCount = box[0];
            int unitPerBox = box[1];

            if(boxCount <= truckSize){
                totalUnits += (boxCount * unitPerBox);
                truckSize -= boxCount;
            }
            else{
                totalUnits += (truckSize * unitPerBox);
                break;
            }
        }

        for(int i = 0 ; i < boxTypes.size() ; i++){
            for(int j = 0 ; j < boxTypes[i].size() ; j++){
                cout<<boxTypes[i][j]<< " ";
            }
            cout<< endl;
        }
        return totalUnits;
    }
};