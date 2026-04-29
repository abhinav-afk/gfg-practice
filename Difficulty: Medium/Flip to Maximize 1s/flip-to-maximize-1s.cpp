class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;
        
        // Count existing 1s
        for(int x : arr) {
            if(x == 1) totalOnes++;
        }
        
        int curr = 0, maxGain = 0;
        
        // Kadane's Algorithm
        for(int x : arr) {
            int val = (x == 0) ? 1 : -1;
            
            curr = max(val, curr + val);
            maxGain = max(maxGain, curr);
        }
        
        return totalOnes + maxGain;
    }
};