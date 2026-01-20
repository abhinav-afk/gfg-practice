class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l,m,h;
        l=0;
        h=arr.size()-1;
        while(h>l){
            m=l+(h-l)/2;
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){
                return m;
            }
            else if(arr[m]<arr[m-1]){
                h=m;
            }
            else{
                l=m;
            }
        }
        return 0;
    }
};