class Solution {
  public:
    int longestSubstr(string& s, int k) {
        vector<int> freq(26, 0);
        
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;
        
        for(int right = 0; right < s.size(); right++) {
            // Add current character
            freq[s[right] - 'A']++;
            
            // Update max frequency in window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            // If window is invalid, shrink it
            while((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};