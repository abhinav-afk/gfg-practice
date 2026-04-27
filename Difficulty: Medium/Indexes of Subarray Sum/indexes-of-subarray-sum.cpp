class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int len=arr.size();
        int low=0,high;
        int sum=0;
        for(int i=0;i<len;i++){
            sum=sum+arr[i];
            high=i;
            if(sum>target){
                while(sum>target){
                    sum=sum-arr[low];
                    low++;
                }
                if(sum==target){
                    low=low+1;
                    high=high+1;
                    arr.clear();
                    arr.push_back(low);
                    arr.push_back(high);
                    return arr;
                }
            }
            else if(sum==target){
                low=low+1;
                high=high+1;
                arr.clear();
                arr.push_back(low);
                arr.push_back(high);
                return arr;
            }
            else continue;
        }
        arr.clear();
        arr.push_back(-1);
        return arr;
    }
};

