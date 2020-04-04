class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int noneZeroIdx = 0;    // pointer tjat just works on the non-zero elements of the array
        for(int i = 0; i < nums.size(); ++i) {
            if(nums.at(i) != 0) {
                if(i != noneZeroIdx) {      // opimal condition
                    nums[noneZeroIdx] = nums[i];
                    nums[i] = 0;
                }
                ++noneZeroIdx;
            }
        }
    }
}; 