class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        vector<int> arr(3);

        long long result = 0;
        for(int right = 0 ; right < n ; right++){
            arr[s[right] - 'a']++;
            while(arr[0] > 0 && arr[1] > 0 && arr[2] > 0){
                result += (n - right);
                arr[s[left] - 'a']--;
                left++;
            }
        }

        return (int)result;
    }
};