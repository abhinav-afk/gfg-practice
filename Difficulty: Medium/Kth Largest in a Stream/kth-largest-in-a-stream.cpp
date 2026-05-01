class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);

            if (minHeap.size() > k) {
                minHeap.pop();
            }

            if (minHeap.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(minHeap.top());
            }
        }

        return result;
    }
};