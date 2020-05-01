class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        std::for_each(nums.begin(), nums.end(), [&result](const int& n) {
            // using XOR operation (ex, a⊕b⊕a=(a⊕a)⊕b=0⊕b=b)
            result = (result ^ n);
        });
        return result;
    }
};