class Solution {
public:
    long long findTime(vector<int> &arr, int hourly){
        long long totalHours = 0;
        for(int i=0;i<arr.size();i++){
            totalHours += ceil((double)arr[i] / (double)hourly);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxEle = INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i] > maxEle){
                maxEle = piles[i];
            }
        }
        
        int low = 1;
        int high = maxEle;

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long reqTime = findTime(piles, mid);

            if(reqTime <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};