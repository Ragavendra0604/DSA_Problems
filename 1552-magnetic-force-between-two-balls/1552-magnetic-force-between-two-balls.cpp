class Solution {
public:
    bool checkPossible(vector<int> &arr, int dist, int m){
        int last = arr[0], cntForce = 1;

        for(int i=1;i<arr.size();i++){
            if(arr[i] - last >= dist){
                cntForce++;
                last = arr[i];
            }
            if(cntForce >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n = position.size();

        int low = 1;
        int high = position[n - 1] - position[0];

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(checkPossible(position, mid, m) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};