class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        
        vector<pair<int,int>> v;
        
        // Store {difference, index}
        for(int i = 0; i < n; i++) {
            v.push_back({abs(a[i] - b[i]), i});
        }
        
        // Sort in descending order of difference
        sort(v.rbegin(), v.rend());
        
        int profit = 0;
        
        for(auto &it : v) {
            int i = it.second;
            
            // Prefer machine with higher profit
            if((a[i] >= b[i] && x > 0) || y == 0) {
                profit += a[i];
                x--;
            }
            else {
                profit += b[i];
                y--;
            }
        }
        
        return profit;
    }
};