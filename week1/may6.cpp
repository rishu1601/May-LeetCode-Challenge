class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityIndex = 0;
        int count = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == nums[majorityIndex]) count += 1;
            else count -= 1;
            if(count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }
        return nums[majorityIndex];
    }
};
