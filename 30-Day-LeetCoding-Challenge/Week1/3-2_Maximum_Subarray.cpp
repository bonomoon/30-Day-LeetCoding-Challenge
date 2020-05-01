class Solution {
public:
    // solved by divide & conquer approach - time-complexity: O(nlogn), space-complexity: O(1)
    int solve(const int& left, const int& right, vector<int>& nums) {
        if(left == right) {      // base case
            return nums.at(left);
        }
        
        int p = (left + right) / 2;     // middle pivot
        
        // get the largest sum of cross subarray between subarrays
        int sum = nums.at(p);
        int left_sum = sum;     
        for(int i = p - 1; i >= left; --i) {
            sum += nums.at(i);
            left_sum = max(sum, left_sum);
        }
        
        sum = nums.at(p + 1);
        int right_sum = sum;
        for(int i = p + 2; i <= right; ++i) {
            sum += nums.at(i);
            right_sum = max(sum, right_sum);
        }
        
        sum = left_sum + right_sum;     // the largest sum of cross subarray

        return max(max(solve(left, p, nums), solve(p + 1, right, nums)), sum);
    }
    
    int maxSubArray(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }
};