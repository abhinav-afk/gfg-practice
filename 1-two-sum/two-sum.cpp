class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ReAnkushwa{};
        for(int i=0;i<nums.size();i++){
            
            // ReAnkushwa[nums[i]]=i;
            if(ReAnkushwa.find(target-nums[i])!=ReAnkushwa.end()){
                return {ReAnkushwa[target-nums[i]],i};
            }
            else{
                
                ReAnkushwa[nums[i]]=i;
            }
            
        }
        return {0,0};

    }
};