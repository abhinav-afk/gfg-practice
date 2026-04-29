class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> res;
        
        while(i < a.size() && j < b.size() && k < c.size()) {
            
            // If all elements are equal
            if(a[i] == b[j] && b[j] == c[k]) {
                // Avoid duplicates in result
                if(res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                i++; j++; k++;
            }
            else {
                // Move the pointer with smallest value
                if(a[i] < b[j]) {
                    if(a[i] < c[k]) i++;
                    else k++;
                }
                else {
                    if(b[j] < c[k]) j++;
                    else k++;
                }
            }
        }
        
        return res;
    }
};