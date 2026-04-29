class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Count total number of 1s
        int k = 0;
        for(int x : arr) {
            if(x == 1) k++;
        }
        
        // If no 1s
        if(k == 0) return -1;
        
        // Count zeros in first window of size k
        int zeroCount = 0;
        for(int i = 0; i < k; i++) {
            if(arr[i] == 0) zeroCount++;
        }
        
        int minSwaps = zeroCount;
        
        // Sliding window
        for(int i = k; i < n; i++) {
            // Remove left element
            if(arr[i - k] == 0) zeroCount--;
            
            // Add right element
            if(arr[i] == 0) zeroCount++;
            
            minSwaps = min(minSwaps, zeroCount);
        }
        
        return minSwaps;
    }
};