class Solution {
public:
    // solved by Kadane's Algorithm - time-complexity: O(n), space-complexity: O(1)
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums.at(0), bestSum = currentSum;
        std::for_each(nums.begin() + 1, nums.end(), [&currentSum, &bestSum](const int& num) {
            currentSum = max(num, currentSum + num);
            bestSum = max(currentSum, bestSum);
        });
        return bestSum;
    }
};

