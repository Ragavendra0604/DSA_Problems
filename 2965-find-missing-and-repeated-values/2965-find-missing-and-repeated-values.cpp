class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        int allSum = 0;
        long long sqSum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                allSum += grid[i][j];
                sqSum  += 1LL * grid[i][j] * grid[i][j];
            }
        }

        long long expectSum = (N * (N + 1)) / 2;
        long long expectSquareSum = 1LL * N * (N + 1) * (2LL*N+1) / 6;

        int diff = allSum - expectSum;
        int sqDiff = sqSum - expectSquareSum;

        int sumRM = sqDiff / diff;

        int r = (diff+sumRM) / 2;
        int m = (r - diff);

        return {r, m};
    }
};