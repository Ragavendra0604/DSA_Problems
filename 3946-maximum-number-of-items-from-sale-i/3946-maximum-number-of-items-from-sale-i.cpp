class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> factor(n), price(n);

        for(int i=0;i<n;i++){
            factor[i] = items[i][0];
            price[i] = items[i][1];
        }

        vector<int> gain(n, 1);

        for(int i=0;i<n;i++){
            int freeCnt = 0;
            for(int j=0;j<n;j++){
                if(i!=j && factor[j] % factor[i] == 0){
                    freeCnt++;
                }
            }
            gain[i] = 1 + freeCnt;
        }

        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for(int i=0;i<n;i++){
            vector<int> ndp = dp;
            for(int b=0;b + price[i] <= budget;b++){
                if(dp[b]==-1) continue;
                ndp[b + price[i]] = max(ndp[b + price[i]], dp[b] + gain[i]);
            }

            for(int b = price[i]; b <= budget ; b++){
                if(ndp[b - price[i]] == -1) continue;

                ndp[b] = max(ndp[b], ndp[b - price[i]] + 1);
            }
            dp.swap(ndp);
        }
        return *max_element(dp.begin(), dp.end());;
    }
};