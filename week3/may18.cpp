
class StockSpanner {
public:
    
    vector<pair<int,int> > vp;
    StockSpanner() {
        vp.clear();
    }
    int next(int price) {
        int span = 1;
        int index = vp.size() - 1;
        while(index >= 0 && price >= vp[index].first){
            span += vp[index].second;
            index -= vp[index].second;
        }
        vp.push_back(make_pair(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
