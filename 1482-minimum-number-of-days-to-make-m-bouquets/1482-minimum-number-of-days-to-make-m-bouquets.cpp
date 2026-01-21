class Solution {
public:
    bool possible(vector<int> &arr, int days, int m, int k){
        int n = arr.size();

        int count = 0; 
        int noOfBouquets = 0;

        for(int i=0;i<n;i++){
            if(arr[i] <= days){
                count++;
            }
            else{
                noOfBouquets += (count/k);
                count = 0;
            }
        }
        noOfBouquets += (count/k);
        if(noOfBouquets >= m) return true;
        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m * (long long)k > n) return -1;

        int min = INT_MAX;
        for(int i=0;i<n;i++){
            if(bloomDay[i] < min){
                min = bloomDay[i];
            }
        }

        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(bloomDay[i] > max){
                max = bloomDay[i];
            }
        }

        int low = min;
        int high = max;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};