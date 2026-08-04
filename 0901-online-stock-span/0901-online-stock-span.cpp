class StockSpanner {
vector<int> result;
public:
    StockSpanner() {}
    
    int next(int price) {
        result.push_back(price);

        int count = 0;
        for(int i = result.size() - 1 ; i >= 0 ; i--){
            if(result[i] <= price) count++;
            else break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */