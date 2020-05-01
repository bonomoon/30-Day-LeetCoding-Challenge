// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define uint unsigned int

class Solution {    // using binary search
public:
    int firstBadVersion(int n) {
        uint left = 1, right = n;
        
        while(left <= right) {
            uint mid = (left + right) / 2;
            
            if(isBadVersion(mid)) {     // true
                right = mid - 1;
            } else {        // false
                left = mid + 1;
            }
        }
        
        return left;
    }
};