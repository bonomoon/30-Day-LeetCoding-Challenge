class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> numSet(arr.begin(), arr.end());
        
        int count = count_if(arr.begin(), arr.end(), [&numSet](const int& num) {
           return numSet.count(num + 1);
        });
        
        return count;
    }
};