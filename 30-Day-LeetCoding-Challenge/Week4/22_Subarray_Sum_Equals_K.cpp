class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, cnt = 0;
        map<int, int> cumsum{{0, 1}};
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            cnt += cumsum[sum - k];
            ++cumsum[sum];
        }
        return cnt;
    }
};