class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result{1};
        
        for(int i = 0; i < nums.size() - 1; ++i) {
            result.push_back(nums[i] * result[i]);
        }
        
        for(int i = nums.size() - 1, r = 1; i >= 0; r *= nums[i--]) {
            result[i] *= r;
        }
        
        return result;
    }
};