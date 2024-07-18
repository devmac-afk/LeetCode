class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            if (-nums[i] == nums[j]) {
                return nums[j];
            } 
            else if (-nums[i] < nums[j]) { 
                j--;
            }
            else { 
                i++;
            }
        }
        return -1;
    }
};